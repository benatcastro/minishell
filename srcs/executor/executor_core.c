/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 01:39:21 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"


//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

int	builtin_checker(char **args, char **env)
{
	if (!ft_strncmp(args[0], ENV, 4))
		return (1);
	else if (!ft_strncmp(args[0], PWD, 4))
		return (1);
	else if (!ft_strncmp(args[0], EXIT, 5))
		return (1);
	else if (!ft_strncmp(args[0], EXPORT, 7))
		return (1);
	else if (!ft_strncmp(args[0], ECHO, 5))
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

static void	bin_executor(char **args, char **env)
{
	char	*path;

	path = bin_path_finder(args, env);
	if (path != NULL)
		execve(path, args, env);
}

void	execute_cmds(char **args, char **env)
{
	//ft_doubleprint(args);
	if (builtin_checker(args, env))
		builtins(args, env);
	else
		bin_executor(args, env);
}

void fd_closer(int fd[2][2])
{
	int i;

	i = 0;
	while (i < 2)
	{
		close (fd[0][i]);
		close (fd[1][i]);
		i++;
	}
}

void exec_nopipe(t_command **cmd_table, char **env)
{
	t_command	*temp;
	int		n;
	pid_t	pid;
	int		fd[2];
	int		status;

	temp = (*cmd_table);
	redir_link(&temp, temp->args);
	if (pipe (fd) == -1)
		exit (0);
	pid = fork();
	if (pid == 0)
	{
		if (temp->in != NULL)
		{
			while ((temp->in->next->next != NULL)
				&& (temp->in->next != NULL))
			{
			}
			if (ft_strcmp(temp->in->content[0], LESS))
			{
				if (access(temp->in->content[0], F_OK) == 1)
					exit (0);
			}
			execute_cmds(temp->args, env);
		}
	}
	else
		wait (0);
}

void exec_onepipe(t_command **cmd_table, char **env)
{
	t_command	*temp;
	int		n;
	pid_t	pid[2];
	int		fd[2];
	int		status;

	temp = (*cmd_table);
	if (pipe (fd) == -1)
		exit (0);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		redir_link(temp, temp->args);
		dup2(fd[1], STDOUT_FILENO);
		n = 0;
		while (n++ < 2)
			close (fd[n]);
		execute_cmds(temp->args, env);
	}
	temp = temp->next;
	pid[1] = fork();
	if (pid[1] == 0)
	{
		redir_link(temp, temp->args);
		dup2(fd[0], STDIN_FILENO);
		n = 0;
		while (n++ < 2)
			close (fd[n]);
		execute_cmds(temp->args, env);
	}
	n = 0;
	while (n++ < 2)
		close (fd[n]);
	n = 0;
	while (n++ < 2)
		waitpid(pid[n], &status, 0);
}

void pipe_core(t_command **cmd_table, char **env)
{
	t_command			*temp;
	int				i[2];
	pid_t			pid[3];
	int				fd[2][2];
	int				status;

	i[0] = 1;
	temp = (*cmd_table);
	while (temp->next)
	{
		temp = temp->next;
		i[0]++;
	}
	if (i[0] == 1)
	{
		exec_nopipe(cmd_table, env);
		return ;
	}
	else if (i[0] == 2)
	{
		exec_onepipe(cmd_table, env);
		return ;
	}
	else
	{
		temp = (*cmd_table);
		if (pipe (fd[0]) == -1)
			exit (0);
		if (pipe (fd[1]) == -1)
			exit (0);
		pid[0] = fork();
		if (pid[0] == 0)
		{
			redir_link(&temp, temp->args);
			dup2(fd[0][1], STDOUT_FILENO);
			fd_closer(fd);
			execute_cmds(temp->args, env);
		}
		temp = temp->next;
		i[0]--;
		while (i[0] > 1)
		{
			pid[1] = fork();
			if (pid[1] == 0)
			{
				redir_link(&temp, temp->args);
				dup2(fd[0][0], STDIN_FILENO);
				dup2(fd[1][1], STDOUT_FILENO);
				fd_closer(fd);
				execute_cmds(temp->args, env);
			}
			i[0]--;
			temp = temp->next;
		}
		pid[2] = fork();
		if (pid[2] == 0)
		{
			redir_link(&temp, temp->args);
			dup2(fd[1][0], STDIN_FILENO);
			fd_closer (fd);
			execute_cmds(temp->args, env);
		}
		fd_closer(fd);
		i[1] = 0;
		while (i[1]++ < 3)
			waitpid(pid[i[1]], &status, 0);
	}
}

int	executor_core(char **cmd, char **env)
{
	t_command_table	*table_head;
	t_command_table	*aux;

	table_head = NULL;
	create_command_table(&table_head, cmd);
	aux = table_head;
	while (aux)
	{
		pipe_core(aux->cmds, env);
		//print table for debug
		// print_table(&table_head);
		aux = aux->next;
	}
	return (1);
}
