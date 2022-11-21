/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:45:07 by becastro          #+#    #+#             */
/*   Updated: 2022/11/21 19:23:28 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"
#include "builtins.h"

void	ft_doublestradd(char *arg)
{
	int		i;
	int		c;
	char	**temp;

	c = -1;
	temp = ft_doublestrdup(g_data.env);
	i = ft_doublestrlen(g_data.env);
	ft_doublefree(g_data.env);
	g_data.env = ft_calloc(i + 2, sizeof(char *));
	while (temp[++c])
		g_data.env[c] = temp[c];
	g_data.env[i] = arg;
	ft_doublefree(temp);
}

int	export_directory_chk(char *arg)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while (arg[++i])
		if (arg[i] == '/')
			cont++;
	if (cont == 0)
		return (0);
	else
		return (1);
}

int	export_arg_chkr(char *arg)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while (arg[++i])
		if (arg[i] == '=')
			cont++;
	if ((((arg[0] < 97) || (arg[0] > 122))
			&& ((arg[0] < 65) || (arg[0] > 90)))
		&& (export_directory_chk(arg) == 1))
	{
		g_data.exit_val = 1;
		printf ("Invalid export argument: %s\n", arg);
		return (-1);
	}
	return (cont);
}

void	export_no_arg_var(int *i, int *f, int *c, char **env)
{
	while ((*i) != ft_doublestrlen(env) - 1)
	{
		(*i)++;
		if (env[(*i)][(*f)] < env[(*c)][(*f)])
			(*c) = (*i);
		else if (env[(*i)][(*f)] == env[(*c)][(*f)])
		{
			(*i)--;
			(*f)++;
			continue ;
		}
		(*f) = 0;
	}
}

void	ft_export_no_arg(char	**env)
{
	int		i;
	int		f;
	int		c;
	int		e;
	char	*aux;

	e = 0;
	f = 0;
	while (e != ft_doublestrlen(env) - 1)
	{
		i = e;
		c = i;
		export_no_arg_var(&i, &f, &c, env);
		aux = env[e];
		env[e] = env[c];
		env[c] = aux;
		e++;
	}
	i = -1;
	while (env[++i])
		printf ("declare -x %s\n", env[i]);
}
