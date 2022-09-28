/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:04:47 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/09/28 18:02:21 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "../print_f/libftprintf.h"
# include "../print_f/libft/libft.h"

int		pid_iscorrect(int pid, char *str);
void	join_char(char **msg, char **tmp);
void	print_msg(char **msg, char **tmp);
char	signals_to_strings(char *str);
#endif