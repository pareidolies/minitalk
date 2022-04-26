/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:18:26 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 17:46:13 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define BUFFER_SIZE	4

# define SLEEP_TIME	20000

# define EMPTY "\nThe message is empty. Is there anything you want to say ?\n\n"
# define SIGACTION_ERROR "\nSorry, we could not set up sigaction.\n\n"
# define SENT "\nThe message has been successfully delivered to the server.\n\n"
# define KILL_ERROR "\nWe could not reach the server, did you close it ?\n\n"
# define SERVER_ERROR "\nAn incident has been notified by the server.\n\n"
# define PARAM_ERROR "\nUsage : ./client [PID] [message to send]\n\n"

//client.c
int		send_size(int pid, int len);
int		send_message(int pid, char *message);
int		send_null(int pid);
int		send_all(int pid, char *str);
int		main(int argc, char **argv);

//client_utils.c
int		set_sigaction(void);
int		ft_strisdigit(char *str);
void	ft_putstr_fd_color(char *str, int fd, char *color);
void	handle_signal(int signum, siginfo_t *info, void *context);

#endif
