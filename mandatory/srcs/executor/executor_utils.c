/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/25 21:22:52 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

int	first_pipe(int *pid, t_command *temp, int fd[2][2], int f[2])
{
	g_data.sub_pid = 1;
	if (f[1] == 1)
		first_pipe_more(&pid[0], temp, fd, f);
	else
		first_pipe_only(&pid[0], temp, fd, f);
	return (0);
}

int	middle_pipes(int *pid, t_command *temp, int fd[2][2])
{
	t_redir		*t_in;

	g_data.sub_pid = 1;
	pid[1] = fork();
	if (pid[1] == 0)
	{
		redir_link(&temp, temp->args);
		t_in = temp->in;
		if (t_in != NULL)
			in_redirection(t_in, fd[0]);
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		fd_closer(fd);
		redirection_core(temp);
	}
	return (0);
}

int	last_pipe(int *pid, t_command *temp, int fd[2][2])
{
	t_redir		*t_in;

	g_data.sub_pid = 1;
	pid[2] = fork();
	if (pid[2] == 0)
	{
		redir_link(&temp, temp->args);
		t_in = temp->in;
		if (t_in != NULL)
			in_redirection(t_in, fd[1]);
		dup2(fd[1][0], STDIN_FILENO);
		fd_closer (fd);
		redirection_core(temp);
	}
	fd_closer(fd);
	return (0);
}

void	special_builtins(t_command *temp)
{
	char	**env;
	int		i;

	i = 0;
	env = ft_doublestrdup(g_data.env);
	if (!temp->args[0] || temp->next != NULL || temp->prev != NULL)
		i = 1;
	g_data.sub_pid = 1;
	if (ft_strcmp(temp->args[0], "cd"))
		cd_builtin(temp->args);
	else if (ft_strcmp(temp->args[0], "export"))
	{
		if (i == 1)
			return ((void)ft_doublefree(env));
		if (!temp->args[1])
			ft_export_no_arg(env);
		else
			ft_export_arg(temp->args);
	}
	else if (ft_strcmp(temp->args[0], "unset"))
		unset_builtin(temp->args, i);
	else if (ft_strcmp(temp->args[0], "exit"))
		exit_builtin(temp->args, i);
	ft_doublefree(env);
	g_data.sub_pid = 0;
}

void	exec_morepipes(t_command **cmd_table, pid_t pid[3], int i[2], int f[2])
{
	t_command		*temp;
	int				fd[2][2];

	(void)i;
	if (pipe (fd[0]) == -1 || pipe (fd[1]) == -1)
		exit (0);
	temp = (*cmd_table);
	first_pipe(pid, temp, fd, f);
	special_builtins(temp);
	if (temp->next == NULL)
		return ;
	temp = temp->next;
	while (temp->next != NULL)
	{
		middle_pipes(pid, temp, fd);
		temp = temp->next;
		special_builtins(temp);
	}
	last_pipe(pid, temp, fd);
	special_builtins(temp);
	waitpid(pid[0], &g_data.exit_val, 0);
	waitpid(pid[1], &g_data.exit_val, 0);
	waitpid(pid[2], &g_data.exit_val, 0);
	get_exit_status();
	g_data.sub_pid = 0;
}
