/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:45:07 by becastro          #+#    #+#             */
/*   Updated: 2022/11/16 17:21:50 by umartin-         ###   ########.fr       */
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
	g_data.env = ft_calloc(i + 1, sizeof(char *));
	while (temp[++c])
		g_data.env[c] = temp[c];
	g_data.env[i] = arg;
	g_data.env[i + 1] = 0;
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

void	ft_doubleprint_err(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (str[i])
	{
		write (2, str[i], ft_strlen(str[i]));
		write (2, "\n", 1);
		i++;
	}
}

void	ft_export_no_arg(void)
{
	int		i;
	int		f;
	int		c;
	int		e;
	char	*aux;
	char	**env;

	env = ft_doublestrdup(g_data.env);
	e = 0;
	f = 0;
	while (e != ft_doublestrlen(env) - 1)
	{
		i = e;
		c = i;
		while (i != ft_doublestrlen(env) - 1)
		{
			i++;
			if (env[i][f] < env[c][f])
				c = i;
			else if (env[i][f] == env[c][f])
			{
				i--;
				f++;
				continue ;
			}
			f = 0;
		}
		aux = env[e];
		env[e] = env[c];
		env[c] = aux;
		e++;
	}
	i = 0;
	while (env[++i])
	{
		printf ("declare -x ");
		printf ("%s\n", env[i]);
	}
}

void	export_temp(char **temp, char *str)
{
	char	*t1;
	char	*t2;
	int		i;
	int		c;

	t1 = ft_calloc(num_until_equal(str) + 1, sizeof(char *));
	t2 = ft_calloc((ft_strlen(str) - num_until_equal(str)), sizeof(char *));
	i = -1;
	while (++i < num_until_equal(str))
		t1[i] = str[i];
	t1[i] = 0;
	c = 0;
	i = (num_until_equal(str));
	while (i++ <= (int)ft_strlen(str))
		t2[c++] = str[i];
	t2[c] = 0;
	temp[0] = t1;
	temp[1] = t2;
	temp[2] = NULL;
}

void	ft_export_arg(char **args)
{
	int		i;
	char	**temp;

	i = 0;
	while (args[++i])
	{
		if (export_arg_chkr(args[i]) == -1)
			return ;
		else if (export_arg_chkr(args[i]) == 0)
		{
			if (find_in_env(args[i]) == NULL)
				ft_doublestradd(args[i]);
		}
		else if (export_arg_chkr(args[i]) > 0)
		{
			temp = ft_calloc(2, sizeof(char *));
			export_temp(temp, args[i]);
			if (find_in_env(temp[0]) != NULL)
				rebuild_env(temp[0]);
			ft_doublestradd(args[i]);
		}
	}
}
