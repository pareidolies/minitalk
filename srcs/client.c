#include "../includes/client.h"

int	end;

int	send_message(int pid, char *message)
{
	int	i;
	int	bits;
	char	c;

	i = 0;
	if (!message)
		return (0);
	while (message[i])
	{
		bits = 0;
		c = message[i];
		while (bits < 8)
		{
			if (c & 0x80)
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
			c = c << 1;
			bits++;
			usleep(SLEEP_TIME);
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
		bits++;
		usleep(SLEEP_TIME);
	}
	return (1);
}

char    *get_message(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	int	pid;
	char	*line;

	if (info->si_pid)
		pid = info->si_pid;
	(void) context;
	(void) info;
	if (signum == SIGUSR1)
	{
		ft_putstr_fd_color(MSSG_SENT, 1, ANSI_COLOR_BLUE);
		if (!send_all(pid, get_message(&line)))
		{
			end = 42;
			return;
		}
	}
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("coucou", 1);
	}
}

int	set_sigaction()
{
	struct sigaction        signal;

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
	end = 0;
	return (1);
}

int	send_all(int pid, char *str)
{
	if (!send_message(pid, ft_itoa(getpid())))
		return (0);
	if (!send_message(pid, " : "))
		return (0);
	if (!send_message(pid, str))
		return (0);
	if (!send_null(pid))
		return (0);
	return (1);
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

void	ft_putstr_fd_color(char *str, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);
}

int main(int argc, char **argv)
{
	if (argc < 3 || !ft_strisdigit(argv[1]))
	{
		ft_putstr_fd_color(PARAM_ERROR, 1, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putstr_fd_color(NO_MSSG, 1, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	if (!set_sigaction())
		return (0);
	if (!send_all(ft_atoi(argv[1]), argv[2]))
		return (0);
	while (1)
	{
		if (end == 42)
			return (0);
		pause();
	}
	return (0);
}
