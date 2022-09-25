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
	//ft_printf("%s\n", globaltab);
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
	//ft_printf("%s\n", globaltab);
}

void	signals_to_strings(char *str)
{
	int		i;
	int		j;
	int		l;
	int		res;
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * 100);
	if (!str)
		return ;
	i = 0;
	j = 0;
	while(str[i])
	{
		res = 0;
		l = 0;
		while (l < 8)
		{
			if (str[i] == 49)
				res = res * 2 + 1;
			else
				res *= 2 ;
			i++;
			l++;
		}
		newstr[j]= res;
		j++;
	}
	newstr[j] = '\0';
	ft_printf("%s\n", newstr);
}

/*int		read_eightnb(char *str)
{
	int		i;
	int		l;

	i = 0;
	while (str[i])
	{
		l = 0;
		while (l < 8)
		{
			if (str[i] == '\0')
				return (1);
			l++;
		}
		i++;
	}
	return(0);
}*/

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
		sleep(5);
		//if (read_eightnb(globaltab))
		if (ft_strlen(globaltab) == 24)
		{
			signals_to_strings(globaltab);
			memset(globaltab, '\0', 100);
		}
		sleep(5);
	}
	return (0);
}
