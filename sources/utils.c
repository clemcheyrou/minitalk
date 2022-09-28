/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:05:43 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/28 18:02:09 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_iscorrect(int pid, char *str)
{
	int	i;

	i = -1;
	if (pid <= 0)
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
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
