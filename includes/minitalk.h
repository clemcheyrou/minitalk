#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "../print_f/libftprintf.h"
# include "../print_f/libft/libft.h"


extern char	g_stock[9];

/*						UTILS						*/
int	ft_atoi(const char *str);
int	pid_iscorrect(int pid, char *str);
void *ft_realloc(void *str, size_t size);
#endif