/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:15:31 by becastro          #+#    #+#             */
/*   Updated: 2022/12/12 15:57:43 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int	ft_isnum(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		if ((c[i] < '0') || (c[i] > '9'))
			return (1);
	}
	return (0);
}

void	exit_args(char **str)
{
	int	c;
	int	b;

	b = 0;
	c = -1;
	if (str[2] != NULL)
	{
		printerr("%sexit: exit: too many arguments\n", PROMPT_ERR);
		g_data.exit_val = 1;
	}
	else if (ft_isnum(str[1]) != 0)
	{
		printerr("%sexit: numeric argument required\n", PROMPT_ERR);
		g_data.exit_val = 255;
		b = 1;
	}
	else if (b == 0)
		g_data.exit_val = ft_atoi(str[1]);
}

void	exit_builtin(char **str, int i)
{
	if (str == NULL && i == 0)
	{
		ft_doublefree(g_data.env);
		printf("exit\n");
		exit(g_data.exit_val);
	}
	if (str[1] != NULL)
		exit_args(str);
	if (i == 0)
	{
		ft_doublefree(g_data.env);
		printf("exit\n");
		exit(g_data.exit_val);
	}
}
