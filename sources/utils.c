#include "minitalk.h"

int ft_len(char*str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	pid_iscorrect(int pid, char *str)
{
	int	i;

	i = -1;
	if (pid <= 0)
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return(0);
	return(1);
}
