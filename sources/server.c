#include "minitalk.h"

char globaltab[100];

void	handle_sigusr1(int sig)
{
	(void)sig;
	int	i;

	i = 0;
	if (globaltab[0] == '\0')
		globaltab[i] = '1';
	else
	{
		while (globaltab[i] != '\0')
			i++;
		globaltab[i] = '1';
		globaltab[i + 1] = '\0';
	}
	ft_printf("%s\n", globaltab);
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	int	i;

	i = 0;
	if (globaltab[0] == '\0')
		globaltab[i] = '0';
	else
	{
		while (globaltab[i] != '\0')
			i++;
		globaltab[i] = '0';
		globaltab[i + 1] = '\0';
	}
	ft_printf("%s\n", globaltab);
}

char	*signals_to_strings(char *str)
{
	int		i;
	int		res;

	if (!str)
		return (NULL);
	while(str)
		i = 0;
		res = 0;
   	while (i < 8)
    {
		if (str[i] == 49)
			res = res * 2 + 1;
		else
			res *= 2 ;
		i++;
	}
	memset(str, '\0', 100);
	str[0] = res;
	return (str);
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
		signals_to_strings(globaltab);
		printf("%s\n", globaltab);
		sleep(5);
	}
	return (0);
}
