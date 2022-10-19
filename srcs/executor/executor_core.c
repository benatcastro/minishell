/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/10/19 19:39:35 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>


//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

int	builtin_checker(char **args, char **env)
{
	if (!ft_strncmp(args[0], "env", 4))
		return (1);
	else if (!ft_strncmp(args[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(args[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(args[0], "export", 7))
		return (1);
	else if (!ft_strncmp(args[0], "echo", 5))
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

static char	*bin_path_finder(char **args, char **env)
{
	char	*path;
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

static char	*bin_executor(char **args, char **env)
{
	char	*path;

	path = bin_path_finder(args, env);
	//printf("%s\n", temp);
	if (path != NULL)
		execve(path, args, env);
	//printf("sexoooooo\n");
	return path;
}

static int	execute_cmds(t_command_table *cmd, char **env)
{
	if (builtin_checker(cmd->cmds[0]->args, env))
		builtins(cmd, env);
	else
		bin_executor(cmd->cmds[0]->args, env);
	exit(1);
}


int	executor_core(char **cmd, char**env)
{
	t_command_table	*cmd_table;
	pid_t			f;

	//print_double_str(cmd);
	cmd_table = NULL;
	create_command_table(&cmd_table, cmd);
	f = fork();
	if (f == 0)
		execute_cmds(cmd_table, env);
	else
		wait(NULL);
	return (1);
}
