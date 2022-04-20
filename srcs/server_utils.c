#include "../includes/server.h"

char	*message;

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	start = 0;
	int		pid;

	(void) context;
	if (info->si_pid)
		pid = info->si_pid;
	if (start == 0)
	{
		start = receive_len(signum);
		if (start == -1)
			ft_putstr_fd_color(MALLOC, 1, ANSI_COLOR_BLUE);
			
	}
	else
	{
		start = receive_mssg(signum, pid);
	}
}

int	set_sigaction()
{
	struct sigaction	signal;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
	{
		ft_putstr_fd(SIGUSR_ERROR, 2);
		return (0);
	}
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		ft_putstr_fd(SIGUSR_ERROR, 2);
		return (0);
	}
	message = malloc(sizeof(char));
	message[0] = '\0';
	return (1);
}

void say_hello()
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
