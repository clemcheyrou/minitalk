#include "minitalk.h"

char *globaltab = NULL;

void	handle_sigusr1(int sig)
{
	(void)sig;
	int	i;

	i = 0;
	ft_printf("1");
	if (globaltab == NULL)
		globaltab = malloc(9);
	while (globaltab[i] != '\0')
		i++;
	globaltab[i] = 1;
	globaltab[i + 1] = '\0';
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	int	i;

	i = 0;
	ft_printf("0");
	if (globaltab == NULL)
		globaltab = malloc(9);
	while (globaltab[i] != '\0')
		i++;
	globaltab[i] = 0;
	globaltab[i + 1] = '\0';
}

char	*signals_to_strings(char *str)
{
	int		i;
	int		j;
	int		res;
	char	*new_str;

	j = ft_strlen(str);
	new_str = ft_realloc(str, 8);
	if (!new_str)
		return (NULL);
	i = 0;
	res = 0;
    while (i < 8)
    {
		if (new_str[j - 8] == 49)
			res = res * 2 + 1;
		else
			res *= 2 ;
		j++;
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	main(void)
{
	int	my_pid;
	struct sigaction sa;
	struct sigaction sb;

	my_pid = getpid();
	printf("PID = %d\n", my_pid);
	sa.sa_handler = &handle_sigusr1;
	sb.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		if (ft_strlen(globaltab) == 8)
		{
			ft_printf("ftlen : %d\n", ft_strlen(globaltab));
			//signals_to_strings(globaltab);
			sleep(5);
		}
	}
	return (0);
}
