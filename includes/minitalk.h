#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

extern char	g_stock[9];

/*						UTILS						*/
int	ft_strlen(char *str);
int	ft_atoi(const char *str);
int	pid_iscorrect(int pid, char *str);

#endif