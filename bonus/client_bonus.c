/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:17:42 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 14:17:47 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	g_end;

int	send_bit(int pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			return (0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			return (0);
		}
	}
	usleep(SLEEP_TIME);
	return (1);
}

int	send_size(int pid, int len)
{
	unsigned int	mask;
	int				bits;

	mask = 0x8000;
	bits = 0;
	while (bits < 16)
	{
		if (!send_bit(pid, len & mask))
			return (0);
		len = len << 1;
		bits++;
	}
	return (1);
}

int	send_message(int pid, char *message)
{
	int				i;
	int				bits;
	unsigned char	c;
	unsigned int	mask;

	mask = 0x80;
	i = 0;
	if (!message)
		return (0);
	while (message[i])
	{
		bits = 0;
		c = message[i];
		while (bits < 8)
		{
			if (!send_bit(pid, c & mask))
				return (0);
			c = c << 1;
			bits++;
		}
		i++;
	}
	return (1);
}

int	send_null(int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			return (0);
		}
		usleep(SLEEP_TIME);
		bits++;
		if (bits == 8)
		{
			g_end = 42;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	g_end = 0;
	if (argc != 3 || !ft_strisdigit(argv[1]))
	{
		ft_putstr_fd_color(PARAM_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putstr_fd_color(EMPTY, 2, ANSI_COLOR_LIGHT_RED);
		return (1);
	}
	if (!set_sigaction())
		return (1);
	pid = ft_atoi(argv[1]);
	if (!send_size(pid, ft_strlen(argv[2]) + 1))
		return (1);
	if (!send_message(pid, argv[2]))
		return (1);
	if (!send_null(pid))
		return (1);
	sleep(10);
	return (0);
}
