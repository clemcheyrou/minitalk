/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:06:51 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/28 17:55:02 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sigusr1(int sig)
{
	(void)sig;

	ft_printf("Message recu\n");
}

static void	string_to_signals(char *str, int server_pid)
{
	int		size;
	int		i;
	char	tmp;
	int		j;

	if (str == NULL)
		return ;
	size = ft_strlen(str);
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		j = 7;
		while (j >= 0)
		{
			if (tmp & (1 << j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j--;
			usleep(800);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sc;
	int	server_pid;
	
	sc.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sc, NULL);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (pid_iscorrect(server_pid, argv[1]))
			string_to_signals(argv[2], server_pid);
		while(1)
		{
			usleep(100);
		}
	}
	else
		printf("Error\n");
	return (0);
}
