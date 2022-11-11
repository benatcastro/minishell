/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:32 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/08 21:37:05 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"

void	in_redirection(t_redir *t, int fd[2][2])
{
	while (t->next != NULL)
	{
		if (access(t->content[1], F_OK) == -1)
			exit (0);
		t = t->next;
	}
	if (ft_strcmp(t->content[0], LESS))
	{
		if (access(t->content[1], F_OK) == -1)
			exit (0);
		else
			fd[0][0] = open(t->content[1], O_RDONLY);
	}
	else if (ft_strcmp(t->content[0], DOUBLELESS))
	{
		fd[0][0] = open(".temp", O_CREAT | O_RDWR
				| O_TRUNC | O_APPEND, 0644);
		doubleless_func(t->content[1], fd[0][0]);
		fd[0][0] = open(".temp", O_RDONLY);
	}
}

void	out_redirection(t_command *temp,
						t_redir *t_out, int fd[2][2], char	**env)
{
	while (t_out->next != NULL)
	{
		if (access(t_out->content[1], F_OK) == -1)
			fd[1][1] = open(t_out->content[1], O_CREAT | O_RDWR, 0644);
		t_out = t_out->next;
	}
	if (ft_strcmp(t_out->content[0], GREATER))
		fd[1][1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
	else if (ft_strcmp(t_out->content[0], DOUBLEGREATER))
		fd[1][1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_APPEND, 0644);
	dup2(fd[0][0], STDIN_FILENO);
	dup2(fd[1][1], STDOUT_FILENO);
	execute_cmds(temp->args, env);
	fd_closer(fd);
}

void	redirection_core(t_command *temp, int fd[2][2], char **env)
{
	t_redir		*t;
	t_redir		*t_out;

	t = temp->in;
	t_out = temp->out;
	if (t != NULL)
		in_redirection(t, fd);
	if (t_out == NULL)
	{
		dup2(fd[0][0], STDIN_FILENO);
		execute_cmds(temp->args, env);
		ft_putstr_fd("unai folla coños\n", 2);
		fd_closer(fd);
	}
	else if (t_out != NULL)
		out_redirection(temp, t_out, fd, env);
	fd_closer(fd);
}