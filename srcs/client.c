#include "../includes/client.h"
//#include "../libft/libft.h"
#include <stdio.h>

t_client	client;

void	send_message(int pid, char *message)
{
	int	i;
	int	bits;
	char	c;

	i = 0;
	if (!message)
		ft_putstr_fd(NO_MSSG, 1);
	while (message[i])
	{
		bits = 0;
		c = message[i];
		while (bits < 8)
		{
			//1
			if (c & 0x80)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_putstr_fd(SIGUSR_ERROR, 2);
			}
			//0
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_putstr_fd(SIGUSR_ERROR, 2);
			}
			c = c << 1;
			bits++;
			usleep(500);
		}
		i++;
	}
}

void	send_null(int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_putstr_fd(SIGUSR_ERROR, 2);
		bits++;
		usleep(500);
	}
}

char    *get_message(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	char	*line;

	(void) context;
	(void) info;
	if (signum == SIGUSR1)
	{
		ft_putstr_fd(ANSI_COLOR_BLUE, 1);
		ft_putstr_fd(MSSG_SENT, 1);
		ft_putstr_fd(ANSI_COLOR_RESET, 1);
		ft_putstr_fd("\n", 1);
		send_all(client.pid, get_message(&line));
		ft_putstr_fd("\n", 1);
	}
	if (signum == SIGUSR2)
		ft_putstr_fd(SERVER_ERROR, 1);
}

void	set_sigaction()
{
	struct sigaction        signal;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
		ft_putstr_fd(SIGUSR_ERROR, 2);
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
		ft_putstr_fd(SIGUSR_ERROR, 2);
	client.bits = 0;
	client.character = 0;
}

void	send_all(int pid, char *str)
{
	send_message(pid, ft_itoa(getpid()));
	send_message(pid, " : ");
	send_message(pid, str);
	send_null(pid);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return(0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc < 3 || !ft_strisdigit(argv[1]))
		ft_putstr_fd(PARAM_ERROR, 1);
	set_sigaction();
	client.pid = ft_atoi(argv[1]);
	send_all(client.pid, argv[2]);
	while (1)
	{
		pause();
	}
	return 0;
}
