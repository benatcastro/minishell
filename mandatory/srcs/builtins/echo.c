/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:48:45 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 21:52:50 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_arg_checker(char *buf)
{
	int	c;

	c = 1;
	if (buf[0] != '-' || buf[1] != 'n')
		return (-1);
	else
	{
		while (buf[++c])
			if (buf[c] != 'n')
				return (-1);
	}
	return (0);
}

void	echo_utils(char **cont, int i)
{
	while (cont[++i])
	{
		if (ft_strcmp(cont[i], ""))
			continue ;
		printf("%s", cont[i]);
		if (cont[i + 1] != NULL)
			printf(" ");
	}
}

void	builtins_echo(char **cont)
{
	int	i;

	if (!cont[1])
		return ((void)printf("\n"));
	if (first_arg_checker(cont[1]) == 0)
	{
		i = 1;
		echo_utils(cont, i);
	}
	else
	{
		i = 0;
		echo_utils(cont, i);
		printf("\n");
	}
}
