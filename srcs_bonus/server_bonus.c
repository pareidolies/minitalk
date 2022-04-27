/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:18:05 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 14:18:07 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	*g_message;

void	throw_errors(int error)
{
	if (error == -1)
	{
		ft_putstr_fd_color(MALLOC, 2, ANSI_COLOR_LIGHT_RED);
		exit(EXIT_FAILURE);
	}
	else if (error == -2)
	{
		ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		exit(EXIT_FAILURE);
	}
	else if (error == -3)
	{
		ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		free(g_message);
		exit(EXIT_FAILURE);
	}
}

int	receive_len(int signum, int pid)
{
	static unsigned int	len = 0;
	static int			bits = 0;	

	len |= (signum == SIGUSR1);
	bits++;
	if (bits == 16)
	{
		g_message = malloc(len * sizeof(char));
		if (!g_message)
			throw_errors(-1);
		len = 0;
		bits = 0;
		if (kill(pid, SIGUSR1) == -1)
			throw_errors(-3);
		return (pid);
	}
	else
	{
		len = len << 1;
		if (kill(pid, SIGUSR1) == -1)
			throw_errors(-2);
		return (0);
	}
}

int	receive_mssg(int signum, int pid)
{
	static unsigned char	c = 0;
	static int				bits = 0;
	static int				i = 0;

	c |= (signum == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		g_message[i] = c;
		if (c == '\0')
		{
			print_message(pid);
			bits = 0;
			i = 0;
			return (0);
		}
		bits = 0;
		c = 0;
		i++;
	}
	else
		c = c << 1;
	if (kill(pid, SIGUSR1) == -1)
		throw_errors(-3);
	return (pid);
}

void	print_message(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
		throw_errors(-3);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(g_message, 1);
	free(g_message);
	ft_putstr_fd("\n\n", 1);
	if (kill(pid, SIGUSR1) == -1)
		throw_errors(-3);
	ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	if (argc > 1)
	{
		ft_putstr_fd_color(PARAMETER_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	say_hello();
	pid = getpid();
	if (!set_sigaction())
		return (0);
	ft_putstr_fd(HI, 1);
	ft_putstr_fd(ANSI_COLOR_LIGHT_WHITE, 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(ANSI_COLOR_RESET, 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
	while (1)
	{
	}
	return (0);
}
