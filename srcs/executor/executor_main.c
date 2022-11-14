/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:34 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/14 18:41:35 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

int	builtin_checker(char **args)
{
	if (!ft_strncmp(args[0], "env", 4))
		return (1);
	else if (!ft_strncmp(args[0], CD, 3))
		return (1);
	else if (!ft_strncmp(args[0], PWD, 4))
		return (1);
	else if (!ft_strncmp(args[0], EXIT, 5))
		return (1);
	else if (!ft_strncmp(args[0], EXPORT, 7))
		return (1);
	else if (!ft_strncmp(args[0], ECHO, 5))
		return (1);
	else if (!ft_strncmp(args[0], UNSET, 6))
		return (1);
	else
		return (0);
}

char	*env_path_maker(char *val, int *i)
{
	int	r;
	int	n;

	n = 4;
	r = 0;
	while (g_data.env[*i][++n])
		val[r++] = g_data.env[*i][n];
	val[r] = 0;
	return (val);
}

char	*bin_path_finder(char **args)
{
	char	*temp;
	char	**p;
	int		i;

	if (!find_in_env("PATH"))
		return (NULL);
	i = -1;
	while (g_data.env[++i])
	{
		if ((!ft_strncmp("PATH", g_data.env[i], 4)))
		{
			temp = ft_calloc(sizeof(char *),
					(ft_strlen(g_data.env[i]) - 5));
			temp = env_path_maker(temp, &i);
			break ;
		}
	}
	p = ft_split_exec(temp, 58);
	i = -1;
	temp = NULL;
	while (p[++i])
	{
		temp = ft_strjoin(p[i], args[0]);
		if (!access(temp, X_OK))
			return (temp);
	}
	return (temp = NULL, temp);
}

static void	bin_executor(char **args)
{
	char	*path;

	path = bin_path_finder(args);
	if (path)
		execve(path, args, g_data.env);
	else if (!path)
	{
		//rl_on_new_line();
		printf ("%s %s: command not found\n", PROMPT, args[0]);
	}
	exit (1);
}

void	execute_cmds(char **args)
{
	if (!args || args[0] == NULL)
		return ;
	if (arg_is_wildcard(args))
		args = wildcard_core(args);
	if (builtin_checker(args))
		builtins(args);
	else
		bin_executor(args);
}

