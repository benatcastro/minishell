/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:32 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/19 17:53:10 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "signals.h"

char	*double_writer(char *buf)
{
	write (1, "> ", 2);
	buf = gnl(1);
	buf = ft_strdup_n_rem(buf);
	return (buf);
}

void	doubleless_func(char *temp, int fd)
{
	char	*buf;

	if (!temp)
		exit (0);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	buf = NULL;
	buf = double_writer(buf);
	if (buf != NULL && ft_strcmp(buf, temp))
	{
		signal(SIGINT, (void *)signal_reciever);
		signal(SIGQUIT, (void *)signal_reciever);
		return ;
	}
	signal(SIGINT, (void *)signal_reciever);
	signal(SIGQUIT, (void *)signal_reciever);
	if (buf == NULL)
		write(fd, "\n", 1);
	else
	{
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	doubleless_func(temp, fd);
}

void	in_redirection(t_redir *t, int fd[2])
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
		{
			write (2, "BASHado: ", 9);
			write (2, t->content[1], ft_strlen(t->content[1]));
			write (2, ": No such file or directory\n", 28);
			exit (0);
		}
		else
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

void	out_redirection(t_command *temp, t_redir *t_out, int fd[2])
{
	while (t_out->next != NULL)
	{
		if (access(t_out->content[1], F_OK) == -1)
			fd[1] = open(t_out->content[1], O_CREAT | O_RDWR, 0644);
		t_out = t_out->next;
	}
	if (ft_strcmp(t_out->content[0], GREATER))
		fd[1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
	else if (ft_strcmp(t_out->content[0], DOUBLEGREATER))
		fd[1] = open(t_out->content[1], O_CREAT | O_WRONLY
				| O_APPEND, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmds(temp->args);
	if (close (fd[0]))
		return ;
	if (close (fd[1]))
		return ;
}

void	redir_permission_chckr(t_command *temp)
{
	t_redir		*t;
	t_redir		*t_out;

	t = temp->in;
	t_out = temp->out;
	while (t != NULL)
	{
		if (!access(t->content[1], W_OK | R_OK))
		{
			write (2, "BASHado: ", 9);
			write (2, t->content[1], ft_strlen(t->content[1]));
			write (2, ": Permission denied\n", 20);
			exit (1);
		}
		t = t->next;
	}
	while (t_out != NULL)
	{
		if (!access(t_out->content[1], R_OK))
		{
			write (2, "BASHado: ", 9);
			write (2, t_out->content[1], ft_strlen(t_out->content[1]));
			write (2, ": Permission denied\n", 20);
			exit (1);
		}
		t_out = t_out->next;
	}
}

void	redirection_core(t_command *temp)
{
	t_redir		*t;
	t_redir		*t_out;
	int			fd[2];

	t = temp->in;
	t_out = temp->out;
	close (fd[0]);
	close (fd[1]);
	if (t != NULL)
		in_redirection(t, fd);
	if (t_out == NULL && t != NULL)
	{
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		unlink(".temp");
		execute_cmds(temp->args);
	}
	if (t_out == NULL && t == NULL)
		execute_cmds(temp->args);
	else if (t_out != NULL)
		out_redirection(temp, t_out, fd);
	redir_permission_chckr(temp);
	close (fd[0]);
	close (fd[1]);
}
