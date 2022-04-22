#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <stdio.h>

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define BUFFER_SIZE	4

# define SLEEP_TIME	20000

# define NO_MSSG "\nError : There is no message to send. Is there anything you would like to say ?\n\n"
# define SIGACTION_ERROR "\nError : Sorry, we could not set up sigaction.\n\n"
# define MSSG_SENT "\nThe message has been successfully delivered to the server.\n\n"
# define KILL_ERROR "\nError : We did not manage to reach the server, did you close it ?\n\n"
# define SERVER_ERROR "\nError : An incident has been notified by the server.\n\n"
# define PARAM_ERROR "\nError : Please, refer to the following usage : ./client [PID] [message to send]\n\n"

//client.c
int	send_size(int pid, int len);
int	send_message(int pid, char *message);
int	send_null(int pid);
int	send_all(int pid, char *str);
int main(int argc, char **argv);

//client_utils.c
void	handle_signal(int signum, siginfo_t *info, void *context);
int	set_sigaction();
int	ft_strisdigit(char *str);
void	ft_putstr_fd_color(char *str, int fd, char *color);

#endif
