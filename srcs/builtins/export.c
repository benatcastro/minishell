/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:45:07 by becastro          #+#    #+#             */
/*   Updated: 2022/11/14 21:57:37 by umartin-         ###   ########.fr       */
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

int	export_arg_chkr(char *arg)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if ((arg[0] < 97) || (arg[0] > 122))
	{
		printf ("Invalid export argument: %s\n", arg);
		return (-1);
	}
	return (1);
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
	while (++i <= num_until_equal(str))
		t1[i] = str[i];
	t1[i] = 0;
	c = 0;
	i = (num_until_equal(str) + 1);
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
	char	**uns;

	i = 0;
	uns = NULL;
	while (args[++i])
	{
		if (export_arg_chkr(args[i]) == -1)
			return ;
	}
	i = 0;
	while (args[++i])
	{
		temp = ft_calloc(2, sizeof(char *));
		export_temp(temp, args[i]);
		if (!ft_strncmp(args[i], find_in_env(temp[0]), (size_t)ft_strlen(temp[0])))
		{
			uns[0] = ft_strdup("export");
			uns[1] = ft_strdup(temp[1]);
			uns[2] = NULL;
			unset_builtin(uns);
		}
		ft_doublestradd(args[i]);
	}
	return ;
}
