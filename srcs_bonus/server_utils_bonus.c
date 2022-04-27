/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:18:14 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 14:18:15 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

extern char	*g_message;

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	start = 0;
	int			pid;

	(void) context;
	if (info->si_pid)
		pid = info->si_pid;
	if (start == 0)
		start = receive_len(signum, pid);
	else
	{
		if (start != pid)
		{
			free(g_message);
			ft_putstr_fd_color(SERVER_CLOSE, 2, ANSI_COLOR_LIGHT_RED);
			ft_putnbr_fd(start, 2);
			ft_putstr_fd_color(SERVER_CLOSE_2, 2, ANSI_COLOR_LIGHT_RED);
			exit(EXIT_FAILURE);
		}
		start = receive_mssg(signum, pid);
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
	return (1);
}

void	say_hello(void)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd(ANSI_COLOR_BLUE, 1);
	ft_putstr_fd(L1, 1);
	ft_putstr_fd(L2, 1);
	ft_putstr_fd(L3, 1);
	ft_putstr_fd(L4, 1);
	ft_putstr_fd(L5, 1);
	ft_putstr_fd(L6, 1);
	ft_putstr_fd(L7, 1);
	ft_putstr_fd(L8, 1);
	ft_putstr_fd(L9, 1);
	ft_putstr_fd(L10, 1);
	ft_putstr_fd(L11, 1);
	ft_putstr_fd(L12, 1);
	ft_putstr_fd(L13, 1);
	ft_putstr_fd(L14, 1);
	ft_putstr_fd(L15, 1);
	ft_putstr_fd(L16, 1);
	ft_putstr_fd(L17, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(ANSI_COLOR_RESET, 1);
}

void	ft_putstr_fd_color(char *str, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}
