#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define BUFFER_SIZE	4

# define NO_MSSG "There is no message to send.\n"
# define SIGUSR_ERROR "error\n"
# define MSSG_SENT "[Message sent ! Would you like to send a new one ?]\n"
# define SERVER_ERROR "Whoops, the server crashed...\n Maybe you can try again !"
# define PARAM_ERROR "It seems that the numbers of parameters is incorrect...\n We     need the PID and the message to deliver. \n Thank you !\n"

typedef struct s_client
{
	int	pid;
	int	bits;
	char	character;
}	t_client;

char    *get_next_line(int fd);
void	send_all(int pid, char *str);

#endif
