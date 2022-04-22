#include "../includes/server.h"

char	*message;

int	receive_len(int signum, int pid)
{
	static unsigned int	len = 0;
	static int		bits = 0;	

	len |= (signum == SIGUSR1);
	bits++;
	if (bits == 16)
	{
		message = malloc(len * sizeof(int));
		if (!message)
			return(-1);
		printf("LEN : %d\n", len);
		len = 0;
		bits = 0;
		//usleep(SLEEP_TIME);
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			//free(message);
		}
		return (pid);
	}
	else
	{
		len = len << 1;
		//usleep(SLEEP_TIME);
		if (kill(pid, SIGUSR1) == -1)
			ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
}

int	receive_mssg(int signum, int pid)
{
	static unsigned char	c = 0;
	static int		bits = 0;
	static int		i = 0;

	c |= (signum == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		message[i] = c;
		printf("message[i] : %c\n", message[i]);
		if (c == '\0')
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			ft_putnbr_fd(pid, 1);
			ft_putstr_fd(" : ", 1);
			ft_putstr_fd(message, 1);
			free(message);
			bits = 0;
			i = 0;
			ft_putstr_fd("\n\n", 1);
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
			//usleep(SLEEP_TIME);
			//if (kill(pid, SIGUSR1) == -1)
			//	ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
			return (0);
		}
		bits = 0;
		c = 0;
		i++;
	}
	else
		c = c << 1;
	//usleep(SLEEP_TIME);
	if (kill(pid, SIGUSR1) == -1)
	{
		ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		//free(message);
		//return (0);
	}
	return (pid);
}

int main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	if (argc > 1)
	{
		ft_putstr_fd_color(PARAMETER_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	say_hello();
	pid = getpid();
	if (!set_sigaction())
		return (0);
	ft_putstr_fd(WELCOME_MSSG, 1);
	ft_putstr_fd(ANSI_COLOR_LIGHT_WHITE, 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(ANSI_COLOR_RESET, 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd_color(LISTEN, 1, ANSI_COLOR_BLUE);
	//usleep(500);
	while (1)
	{
		pause();
		//usleep(200);
	}
	return (0);
}
