/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:34 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 08:24:02 by becastro         ###   ########.fr       */
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
	if (!ft_strncmp(args[0], ENV, 4))
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

char	*env_path_maker(char *val, char **env, int *i)
{
	int	r;
	int	n;

	n = 4;
	r = 0;
	while (env[*i][++n])
		val[r++] = env[*i][n];
	val[r] = 0;
	return (val);
}

char	*bin_path_finder(char **args, char **env)
{
	char	*temp;
	char	**p;
	int		i;

	i = -1;
	while (env[++i])
	{
		if ((!ft_strncmp("PATH", env[i], 4)))
		{
			temp = ft_calloc(sizeof(char *),
					(ft_strlen(env[i]) - 5));
			temp = env_path_maker(temp, env, &i);
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

static void	bin_executor(char **args, char **env)
{
	char	*path;

	path = bin_path_finder(args, env);
	if (path != NULL)
		execve(path, args, env);
	else
	{
		rl_on_new_line();
		printf("%s%s: command not found\n", PROMPT, args[0]);
	}
	exit (1);
}

void	execute_cmds(char **args, char **env)
{
	if (arg_is_wildcard(args))
		args = wildcard_core(args);
	if (builtin_checker(args))
		builtins(args, env);
	else
		bin_executor(args, env);
}
