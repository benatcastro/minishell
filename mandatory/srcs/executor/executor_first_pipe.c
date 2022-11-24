/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_first_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:16:26 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 15:02:41 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

void	first_pipe_only(int *pid, t_command *temp, int fd[2][2], int f[2])
{
	t_redir		*t_in;

	(*pid) = fork();
	if ((*pid) == 0)
	{
		redir_link(&temp, temp->args);
		t_in = temp->in;
		if (t_in != NULL)
		{
			in_redirection(t_in, fd[f[0]]);
			dup2(fd[f[0]][0], STDIN_FILENO);
			close (fd[f[0]][0]);
			unlink(".temp");
		}
		redir_link(&temp, temp->args);
		redirection_core(temp);
	}
}

void	first_pipe_more(int *pid, t_command *temp, int fd[2][2], int f[2])
{
	t_redir		*t_in;

	(*pid) = fork();
	if ((*pid) == 0)
	{
		redir_link(&temp, temp->args);
		t_in = temp->in;
		if (t_in != NULL)
		{
			in_redirection(t_in, fd[f[0]]);
			dup2(fd[f[0]][0], STDIN_FILENO);
			close (fd[f[0]][0]);
			unlink(".temp");
		}
		dup2(fd[f[0]][1], STDOUT_FILENO);
		fd_closer(fd);
		redirection_core(temp);
	}
}
