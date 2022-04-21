#include "../includes/client.h"

int	end;

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	int	pid;

	if (info->si_pid)
		pid = info->si_pid;
	(void) context;
	(void) info;
	if (signum == SIGUSR1)
	{
		if (end == 42)
			ft_putstr_fd_color(MSSG_SENT, 1, ANSI_COLOR_BLUE);
		return;
	}
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("coucou", 1);
	}
}

int	set_sigaction()
{
	struct sigaction        signal;

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
	end = 0;
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
