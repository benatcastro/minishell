/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:32 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/12 16:09:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "signals.h"

void	permission_printer(t_redir *t, int i)
{
	if (i == 1)
	{
		printerr("%s%s: No such file or directory", PROMPT_ERR, t->content[1]);
		exit (1);
	}
	else if (i == 2)
	{
		printerr("%s%s: Permission denied", PROMPT_ERR, t->content[1]);
		exit (1);
	}
}

void	in_redirection(t_redir *t, int fd[2])
{
	while (t->next != NULL)
	{
		if (ft_strcmp(t->content[0], DOUBLELESS))
			heredoc_utils(t->content[1], fd[0]);
		else if (access(t->content[1], F_OK) == -1)
			exit (0);
		t = t->next;
	}
	if (ft_strcmp(t->content[0], LESS))
	{
		if (access(t->content[1], F_OK) == -1)
			permission_printer(t, 1);
		else
			if (access(t->content[1], R_OK) == -1)
				permission_printer(t, 2);
		fd[0] = open(t->content[1], O_RDONLY);
	}
	else if (ft_strcmp(t->content[0], DOUBLELESS))
	{
		fd[0] = open(".temp", O_CREAT | O_RDWR
				| O_TRUNC | O_APPEND, 0644);
		doubleless_func(t->content[1], fd[0]);
		fd[0] = open(".temp", O_RDONLY);
	}
}

void	out_redirection_utils(t_redir *t_out, int fd[2])
{
	while (t_out != NULL)
	{
		if (access(t_out->content[1], F_OK) == -1)
			fd[1] = open(t_out->content[1], O_CREAT | O_RDWR, 0644);
		else
		{
			if (access(t_out->content[1], W_OK) == -1)
				permission_printer(t_out, 2);
			else
				open(t_out->content[1], O_TRUNC);
		}
		t_out = t_out->next;
	}
}

void	out_redirection(t_command *temp, t_redir *t_out,
			t_redir *head, int fd[2])
{
	head = t_out;
	out_redirection_utils(t_out, fd);
	t_out = head;
	while (t_out->next != NULL)
		t_out = t_out->next;
	if (ft_strcmp(t_out->content[0], GREATER))
		fd[1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
	else if (ft_strcmp(t_out->content[0], DOUBLEGREATER))
		fd[1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_APPEND, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmds(temp->args);
	close (fd[0]);
	close (fd[1]);
}

void	redirection_core(t_command *temp)
{
	t_redir		*head;
	t_redir		*t_out;
	int			fd[2];

	t_out = temp->out;
	head = NULL;
	if (t_out == NULL)
		execute_cmds(temp->args);
	else if (t_out != NULL)
		out_redirection(temp, t_out, head, fd);
	close (fd[0]);
	close (fd[1]);
}
