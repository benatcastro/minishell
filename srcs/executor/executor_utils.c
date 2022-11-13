/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 16:35:52 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

int	first_pipe(int *pid, t_command *temp, int fd[2][2], char **env, int f[2])
{
	if (f[1] == 1)
	{
		pid[0] = fork();
		if (pid[0] == 0)
		{
			redir_link(&temp, temp->args);
			dup2(fd[f[0]][1], STDOUT_FILENO);
			fd_closer(fd);
			redirection_core(temp, env);
		}
	}
	else
	{
		pid[0] = fork();
		if (pid[0] == 0)
		{
			redir_link(&temp, temp->args);
			redirection_core(temp, env);
		}
	}
	waitpid(pid[0], NULL, 0);
	g_data.sub_pid = 0;
	return (0);
}

int	middle_pipes(int *pid, t_command *temp, char **env, int fd[2][2])
{
	pid[1] = fork();
	if (pid[1] == 0)
	{
		redir_link(&temp, temp->args);
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		fd_closer(fd);
		redirection_core(temp, env);
	}
	return (0);
}

int	last_pipe(int *pid, t_command *temp, int fd[2][2], char **env)
{
	pid[2] = fork();
	if (pid[2] == 0)
	{
		redir_link(&temp, temp->args);
		dup2(fd[1][0], STDIN_FILENO);
		fd_closer (fd);
		redirection_core(temp, env);
	}
	fd_closer(fd);
	return (0);
}

void	exec_morepipes(t_command **cmd_table,
		char **env, pid_t pid[3], int i[2])
{
	t_command		*temp;
	int				fd[2][2];
	int				f[2];

	f[0] = 0;
	f[1] = 1;
	g_data.sub_pid = 1;
	temp = (*cmd_table);
	fd_closer(fd);
	if (pipe (fd[0]) == -1 || pipe (fd[1]) == -1)
		exit (0);
	if (temp->next != NULL && temp->next->next == NULL)
		f[0] = 1;
	if (temp->next == NULL)
		f[1] = 0;
	first_pipe(pid, temp, fd, env, f);
	if (temp->next == NULL)
		return ;
	temp = temp->next;
	while (temp->next != NULL)
	{
		middle_pipes(pid, temp, env, fd);
		temp = temp->next;
	}
	last_pipe(pid, temp, fd, env);
	i[1] = 0;
	while (i[1]++ < 3)
		waitpid(pid[i[1]], NULL, 0);
	g_data.sub_pid = 0;
	unlink(".temp");
}
