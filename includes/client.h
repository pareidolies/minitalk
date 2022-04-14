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

# define SLEEP_TIME	50

# define NO_MSSG "\nThere is no message to send. Is there anything you would like to say ?\n\n"
# define SIGACTION_ERROR "\nSorry, we could not set up sigaction.\n\n"
# define MSSG_SENT "\n[Message sent ! Would you like to send a new one ?]\n\n"
# define KILL_ERROR "\nWe did not manage to reach the server, did you close it ?\n\n"
# define SERVER_ERROR "\nWhoops, the server has just crashed... Maybe you can try again !\n\n"
# define PARAM_ERROR "\nPlease, refer to the following usage : ./client [PID] [message to send]\n\n"

char    *get_next_line(int fd);
int	send_all(int pid, char *str);
void    ft_putstr_fd_color(char *str, int fd, char *color);

#endif
