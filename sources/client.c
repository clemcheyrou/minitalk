#include "minitalk.h"

void	string_to_signals(char *str, int server_pid)
{
	int		size;
	int		i;
	char	tmp;
	int		j;

	if (str == NULL)
		return ;
	size = ft_strlen(str);
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
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	(void)argc;
	server_pid = ft_atoi(argv[1]);
	//string_to_signals("lol", server_pid);
	return (0);
}
