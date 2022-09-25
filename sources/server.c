/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:03:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/25 19:23:43 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_tab[9];

static void	handle_sigusr1(int sig)
{
	int	i;

	(void)sig;
	i = 0;
	if (g_tab[0] == '\0')
		g_tab[i] = '1';
	else
	{
		while (g_tab[i] != '\0')
			i++;
		g_tab[i] = '1';
		g_tab[i + 1] = '\0';
	}
}

static void	handle_sigusr2(int sig)
{
	int	i;

	(void)sig;
	i = 0;
	if (g_tab[0] == '\0')
		g_tab[i] = '0';
	else
	{
		while (g_tab[i] != '\0')
			i++;
		g_tab[i] = '0';
		g_tab[i + 1] = '\0';
	}
}

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

void	join_char(char **msg, char **tmp)
{
	char				letter[2];

	letter[1] = '\0';
	letter[0] = signals_to_strings(g_tab);
	*tmp = ft_strjoin(*msg, letter);
	free(*msg);
	*msg = *tmp;
	ft_memset(g_tab, '\0', 9);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sb;
	int					my_pid;
	char				*msg;
	char				*tmp;

	msg = ft_strdup("");
	my_pid = getpid();
	printf("PID = %d\n", my_pid);
	sa.sa_handler = &handle_sigusr1;
	sb.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		if (ft_strlen(g_tab) == 8)
			join_char(&msg, &tmp);
		else if (ft_strlen(g_tab) == 0 && msg[0] != 0)
			print_msg(&msg, &tmp);
		usleep(1000);
	}
	free(tmp);
	free(msg);
	return (0);
}
