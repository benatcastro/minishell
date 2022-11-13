/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:45:07 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 05:50:31 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	ft_doublestradd(char **str, char *arg)
{
	int		i;

	i = ft_doublestrlen(str);
	str[i] = arg;
	str[i + 1] = 0;
}

int	export_arg_chkr(char *arg)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (arg[++i])
		if (arg[i] == '=')
			cont++;
	if (cont == 0)
	{
		write (2, "Invalid export argument: ", 25);
		write (2, arg, ft_strlen(arg));
		write (2, "\n", 1);
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

void	ft_export_no_arg(char **cln)
{
	int		i;
	int		f;
	int		c;
	int		e;
	char	*aux;
	char	**env;

	env = ft_doublestrdup(cln);
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
		printf ("%s\n", env[i]);
}

void	ft_export_arg(char **env, char **args)
{
	int	i;

	i = 0;
	while (args[++i])
		if (!export_arg_chkr(args[i]))
			exit (0);
	//ft_doubleprint_err(env);
	i = 0;
	while (args[++i])
		ft_doublestradd(env, args[i]);
	ft_doubleprint_err(env);
	return ;
}
