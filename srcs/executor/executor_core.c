/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/12 19:04:54 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/11/12 23:53:25 by becastro         ###   ########.fr       */
>>>>>>> beta-v2
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

void	fd_closer(int fd[2][2])
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (close (fd[0][i]))
			return ;
		if (close (fd[1][i]))
			return ;
		i++;
	}
}

void	exec_nopipe(t_command **cmd_table, char **env)
{
	t_command	*temp;
	int			n;
	pid_t		pid;
	int			status;

	temp = (*cmd_table);
	redir_link(&temp, temp->args);
	pid = fork();
	if (pid == 0)
		redirection_core(temp, env);
	else
		waitpid (g_data.sub_pid, NULL, 0);
	unlink(".temp");
}

int	exec_onepipe(t_command **cmd_table, char **env)
{
	t_command	*temp;
	pid_t		pid[2];
	int			fd[2];

	temp = (*cmd_table);
	if (pipe (fd) == -1)
		exit (0);
	pid[0] = fork();
	if (pid[0] == 0)
		return (dup2(fd[1], STDOUT_FILENO), redir_link(&temp, temp->args),
			close (fd[0]), close (fd[1]), redirection_core(temp, env), 0);
	temp = temp->next;
	pid[1] = fork();
	if (pid[1] == 0)
		return (dup2(fd[0], STDIN_FILENO), redir_link(&temp, temp->args),
			close (fd[1]), close(fd[0]), redirection_core(temp, env), 0);
	close (fd[0]);
	close (fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	unlink(".temp");
	return (0);
}

void	pipe_core(t_command **cmd_table, char **env)
{
	t_command		*temp;
	int				i[2];
	pid_t			pid[3];

	i[0] = 1;
	temp = (*cmd_table);
	while (temp->next)
	{
		temp = temp->next;
		i[0]++;
	}
	if (i[0] == 1)
		exec_nopipe(cmd_table, env);
	else if (i[0] == 2)
		exec_onepipe(cmd_table, env);
	else
		exec_morepipes(cmd_table, env, pid, i);
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
		aux = aux->next;
	}
	//free_command_table_nodes(&table_head);
	// print_table(&table_head);
	return (1);
}
