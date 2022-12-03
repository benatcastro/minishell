/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:45:32 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 17:17:01 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

extern t_data	g_data;

int	var_checker(char *var)
{
	if (find_in_env(var))
		return (1);
	return (0);
}

void	rebuild_env(char *var)
{
	int		i;
	int		j;
	char	**new_env;

	i = -1;
	j = -1;
	if (!find_in_env(var))
		return ;
	new_env = ft_calloc(ft_doublestrlen(g_data.env), sizeof(char *));
	while (g_data.env[++i])
		if (!env_comparer(var, g_data.env[i]))
			new_env[++j] = ft_strdup(g_data.env[i]);
	ft_doublefree(g_data.env);
	g_data.env = ft_doublestrdup(new_env);
	ft_doublefree(new_env);
}

void	unset_builtin(char **args, int c)
{
	int	i;

	if (c == 1)
		return ;
	if (ft_doublestrlen(args) <= 1)
		return ;
	i = 0;
	while (args[++i])
	{
		if (var_checker(args[i]))
			rebuild_env(args[i]);
		else
			continue ;
	}
}
