#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("1\n");
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	printf("0\n");
}

char	*signals_to_strings(char *str)
{
    int     size;
    int        i;
    int        j;
	int		res;
	char		*s;
	int		l;

    if (str == NULL)
        return (NULL);
    size = ft_strlen(str);
	s = malloc(sizeof(char) * size / 8);
	if (!s)
		return (NULL);
    i = 0;
	l = 0;
    while (i < size)
    {
		res = 0;
		j = 7;
        while (j >= 0)
        {
			if (str[i] == 49)
				res = res * 2 + 1;
			else
				res *= 2 ;
			j--;
			i++;
		}
		s[l] = res;
		l++;
	}
	s[l] = '\0';
	return (s);
}

int	main(int argc, char **argv)
{
	int	my_pid;
	struct sigaction sa = {0};
	struct sigaction sb = {0};

	(void)argc;
	(void)argv;
	my_pid = getpid();
	printf("PID = %d\n", my_pid);
	sa.sa_handler = &handle_sigusr1;
	sb.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		//printf("Wait for msg\n");
		sleep(5);
	}
	return (0);
}
