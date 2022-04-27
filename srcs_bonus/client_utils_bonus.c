/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:17:56 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 14:17:58 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

extern int	g_end;

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGUSR1)
	{
		if (g_end == 42)
		{
			ft_putstr_fd_color(SENT, 1, ANSI_COLOR_BLUE);
			exit (EXIT_SUCCESS);
		}
	}
	if (signum == SIGUSR2)
	{
		ft_putstr_fd_color(SERVER_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		exit (EXIT_FAILURE);
	}
}

int	set_sigaction(void)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
	{
		ft_putstr_fd_color(SIGACTION_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		ft_putstr_fd_color(SIGACTION_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	g_end = 0;
	return (1);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_fd_color(char *str, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}
