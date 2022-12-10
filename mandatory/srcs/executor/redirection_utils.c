/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:21:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/10 14:24:34 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "signals.h"

void	fd_printer(int fd, char *buf)
{
	write(fd, buf, ft_strlen(buf));
	write(fd, "\n", 1);
}

void	doubleless_func(char *temp, int fd)
{
	char	*buf;

	if (!temp)
		exit (0);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	buf = NULL;
	rl_catch_signals = 1;
	while (1)
	{
		buf = readline("> ");
		if (!buf)
		{
			unlink(".temp");
			exit(0);
		}
		if (ft_strcmp(buf, temp))
			return ;
		if (buf == NULL)
			write(fd, "\n", 1);
		else
			fd_printer(fd, buf);
	}
	signal(SIGINT, signal_reciever);
	signal(SIGQUIT, signal_reciever);
}

char	**redir_remover(char **args)
{
	char	**temp;
	int		i;
	int		e;
	int		a;

	i = -1;
	a = 0;
	while (args[++i])
		redirection_ag_var(args, &a, &i);
	if (a == 0)
		return (NULL);
	temp = ft_calloc(a + 1, sizeof(char *));
	i = -1;
	e = 0;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER))
			|| (ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
			i++;
		else
			temp[e++] = ft_strdup(args[i]);
	}
	return (temp);
}

void	heredoc_utils(char *str, int fd)
{
	fd = open(".temp", O_CREAT | O_RDWR
			| O_TRUNC | O_APPEND, 0644);
	doubleless_func(str, fd);
	unlink(".temp");
	close (fd);
}
