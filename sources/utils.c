/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:05:43 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/25 19:22:22 by ccheyrou         ###   ########.fr       */
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

void	print_msg(char **msg, char **tmp)
{
	ft_printf("%s\n", *msg);
	free(*tmp);
	*msg = ft_strdup("");
}
