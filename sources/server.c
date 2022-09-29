/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:03:18 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/29 11:22:02 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_mt
{
	char	tab[9];
	int		client_pid;
}	t_mt;

t_mt	g_mt;

//char	g_mt.tab[9];

static void	handle_sigusr1(int sig, siginfo_t *info, void *ucontext)
{
	int	i;

	(void)sig;
	(void)ucontext;
	g_mt.client_pid = info->si_pid;
	i = 0;
	if (g_mt.tab[0] == '\0')
		g_mt.tab[i] = '1';
	else
	{
		while (g_mt.tab[i] != '\0')
			i++;
		g_mt.tab[i] = '1';
		g_mt.tab[i + 1] = '\0';
	}
}

static void	handle_sigusr2(int sig)
{
	int	i;

	(void)sig;
	i = 0;
	if (g_mt.tab[0] == '\0')
		g_mt.tab[i] = '0';
	else
	{
		while (g_mt.tab[i] != '\0')
			i++;
		g_mt.tab[i] = '0';
		g_mt.tab[i + 1] = '\0';
	}
}

void	join_char(char **msg, char **tmp)
{
	char				letter[2];

	letter[1] = '\0';
	letter[0] = signals_to_strings(g_mt.tab);
	*tmp = ft_strjoin(*msg, letter);
	free(*msg);
	*msg = *tmp;
	ft_memset(g_mt.tab, '\0', 9);
}

void	print_msg(char **msg, char **tmp)
{
	ft_printf("%s\n", *msg);
	free(*tmp);
	*msg = ft_strdup("");
	kill(g_mt.client_pid, SIGUSR1);
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr1;
	sb.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		if (ft_strlen(g_mt.tab) == 8)
			join_char(&msg, &tmp);
		else if (ft_strlen(g_mt.tab) == 0 && msg[0] != 0)
			print_msg(&msg, &tmp);
		usleep(1000);
	}
	free(tmp);
	free(msg);
	return (0);
}
