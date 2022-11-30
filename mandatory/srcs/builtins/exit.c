/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:15:31 by becastro          #+#    #+#             */
/*   Updated: 2022/11/30 18:53:44 by umartin-         ###   ########.fr       */
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
		write (2, "BASHado: exit: too many arguments\n", 34);
		g_data.exit_val = 1;
	}
	if (ft_isnum(str[1]) != 0)
	{
		write (2, "BASHado: exit: numeric argument required\n", 41);
		g_data.exit_val = 255;
		b = 1;
	}
	if (b == 0)
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
