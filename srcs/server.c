#include "../includes/server.h"
#include "../libft/libft.h"
#include <stdio.h>

t_server	server;

void say_hello()
{
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

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	int	pid;

	(void) context;
	(void) info;
	if (info->si_pid)
		pid = info->si_pid;
	//1
	if (signum == SIGUSR1)
		server.character |= (0x80 >> server.bits);
	//0
	else if (signum == SIGUSR2)
		server.character ^= (0x80 >> server.bits);
	server.bits++;
	if (server.bits == 8)
	{
		server.message = ft_strjoin(server.message, &server.character);
		if (server.character == '\0')
		{
			ft_putstr_fd(server.message, 1);
			ft_putstr_fd("\n\n", 1);
			ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("error\n", 2);
			free(server.message);
		}
		server.bits = 0;
		server.character = 0xFF;
	}
}

void	set_sigaction()
{
	struct sigaction	signal;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
		ft_putstr_fd(SIGUSR_ERROR, 2);
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
		ft_putstr_fd(SIGUSR_ERROR, 2);
	server.bits = 0;
	server.message = malloc(sizeof(char));
	server.message[0] = '\0';
	server.character = 0xFF;
}

void	ft_putstr_fd_color(char *str, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(ANSI_COLOR_RESET, fd);	
}

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 1)
		ft_putstr_fd(PARAMETER_ERROR, 2);
	say_hello();
	server.pid = getpid();
	set_sigaction();
	ft_putstr_fd(WELCOME_MSSG, 1);
	ft_putstr_fd(ANSI_COLOR_LIGHT_WHITE, 1);
	ft_putnbr_fd(server.pid, 1);
	ft_putstr_fd(ANSI_COLOR_RESET, 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
	while (1)
		pause();
	return (0);
}
