#include "minitalk.h"

char globaltab[9];

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

// char	*signals_to_strings(char *str)
// {
// 	int		i;
// 	int		l;
// 	int		res;
// 	char	*newstr;

// 	newstr = (char *)malloc(sizeof(char) * 2);
// 	if (!str)
// 		return (NULL);
// 	res = 0;
// 	l = 0;
// 	i = 0;
// 	while (l < 8)
// 	{
// 		if (str[i] == 49)
// 			res = res * 2 + 1;
// 		else
// 			res *= 2 ;
// 		i++;
// 		l++;
// 	}
// 	newstr[0]= res;
// 	newstr[1] = '\0';
// 	return (newstr);
// }

char	signals_to_strings(char *str)
{
	int		i;
	int		l;
	int		res;
	
	res = 0;
	l = 0;
	i = 0;
	while (l < 8)
	{
		if (str[i] == 49)
			res = res * 2 + 1;
		else
			res *= 2 ;
		i++;
		l++;
	}
	return (res);
}
// int	main(void)
// {
// 	struct sigaction 	sa;
// 	struct sigaction 	sb;
// 	int					my_pid;
// 	char msg;
// 	char *letter;

// 	msg[0] = 0;
// 	my_pid = getpid();
// 	printf("PID = %d\n", my_pid);
// 	sa.sa_handler = &handle_sigusr1;
// 	sb.sa_handler = &handle_sigusr2;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sb, NULL);
// 	while (1)
// 	{
// 		if (ft_strlen(globaltab) == 8)
// 		{
// 			letter = signals_to_strings(globaltab);
// 			msg = ft_strjoin(&msg, letter);
// 			free(letter);
// 			ft_memset(globaltab, '\0', 100);
// 		}
// 		else if (ft_strlen(globaltab) == 0 && msg[0] != 0)
// 		{
// 			ft_printf("%s\n", msg);
// 			free(msg);
// 			msg = malloc(sizeof(char) * 1);
// 			msg[0] = 0;
// 		}
// 		usleep(1000);
// 	}
// 	return (0);
// }

int	main(void)
{
	struct sigaction 	sa;
	struct sigaction 	sb;
	int					my_pid;
	char	*msg;
	char	*tmp;
	char	letter[2];

	letter[1] = '\0';
	msg = ft_strdup("");
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
			letter[0] = signals_to_strings(globaltab);
			tmp = ft_strjoin(msg, letter);
			free(msg);
			msg = tmp;
			ft_memset(globaltab, '\0', 9);
		}
		else if (ft_strlen(globaltab) == 0 && msg[0] != 0)
		{
			ft_printf("%s\n", msg);
			free(tmp);
			msg = ft_strdup("");
		}
		usleep(1000);
	}
	free(tmp);
	free(msg);
	return (0);
}
