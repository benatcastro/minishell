/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:34 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/10 15:38:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

extern t_data	g_data;

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

char	*bin_path_finder(char **args, int *exit)
{
	char	*temp;
	char	**p;
	int		i;

	*exit = 0;
	if (!find_in_env("PATH"))
		return (*exit = 1, NULL);
	i = -1;
	temp = find_in_env("PATH") + 5;
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
	int		exec_return;
	int		exit_val;

	exec_return = 0;
	path = bin_path_finder(args, &exit_val);
	if (path)
		exec_return = execve(path, args, g_data.env);
	else
		exec_return = execve(args[0], args, g_data.env);
	if ((exec_return == -1 && exit_val != 1)
		|| (exec_return == 0 && exit_val != 1))
	{
		printerr("%s%s: command not found\n", PROMPT_ERR, args[0]);
		exit (127);
	}
	else if ((exec_return == -1 && exit_val == 1)
		|| (exec_return == 0 && exit_val == 1))
	{
		printerr("%s%s: No such file or directory\n", PROMPT_ERR, args[0]);
		exit (127);
	}
	exit (exec_return);
}

void	execute_cmds(char **args)
{
	char	**cmd;

	if (args && args[0])
		cmd = str_to_double(args[0]);
	if (!args || args[0] == NULL)
		exit(0);
	if (arg_is_wildcard(&args[1]))
		args = ft_doublestrjoin(cmd, wildcard_arg_manager(&args[1]));
	if (builtin_checker(args))
		builtins(args);
	else
		bin_executor(args);
}
