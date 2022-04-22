#include "../includes/client.h"

int	end;

int	send_size(int pid, int len)
{
	unsigned int	mask = 0x8000;
	int		bits;

	bits = 0;
	while (bits < 16)
	{
		if (len & mask)
		{	
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
				return (0);
			}
			usleep(SLEEP_TIME);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
				return (0);
			}
			usleep(SLEEP_TIME);
		}
		//usleep(SLEEP_TIME);
		len = len << 1;
		bits++;
		//pause();
	}
	return(1);
}

int	send_message(int pid, char *message)
{
	int	i;
	int	bits;
	unsigned char	c;

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
				usleep(SLEEP_TIME);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_putstr_fd_color(KILL_ERROR, 2, ANSI_COLOR_LIGHT_RED);
					return (0);
				}
				usleep(SLEEP_TIME);
			}
			c = c << 1;
			bits++;
			//usleep(SLEEP_TIME);
			//pause();
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
		usleep(SLEEP_TIME);
		bits++;
		if (bits == 8)
		{
			end = 42;
		}
		//usleep(SLEEP_TIME);
		//pause();
	}
	return (1);
}

int	send_all(int pid, char *str)
{
	unsigned int	mssg_len;
	int		client_pid;

	client_pid = getpid();
	mssg_len = ft_strlen(str) + 1;
	if (!send_size(pid, mssg_len))
		return (0);
	if (!send_message(pid, str))
		return (0);
	if (!send_null(pid))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	end = 0;

	if (argc < 3 || !ft_strisdigit(argv[1]))
	{
		ft_putstr_fd_color(PARAM_ERROR, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putstr_fd_color(NO_MSSG, 2, ANSI_COLOR_LIGHT_RED);
		return (0);
	}
	if (!set_sigaction())
		return (0);
	if (!send_all(ft_atoi(argv[1]), argv[2]))
		return (0);
	sleep(10);
	/*while (1)
	{
	//	if (end == 42)
	//		return (0);
	//	pause();
		usleep(200);
	}*/
	return (0);
}
