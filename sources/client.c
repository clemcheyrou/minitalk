#include "minitalk.h"

void	string_to_signals(char *str, int server_pid)
{
	int		size;
	int		i;
	char	tmp;
	int		j;

	if (str == NULL)
		return ;
	size = ft_len(str);
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		j = 7;
		while (j >= 0)
		{
			if (tmp & (1 << j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j--;
			usleep(1000);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (pid_iscorrect(server_pid, argv[1]))
			string_to_signals(argv[2], server_pid);
	}
	else
		printf("Error\n");
	return (0);
}
