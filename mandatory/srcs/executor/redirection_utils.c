/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:21:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 16:55:22 by umartin-         ###   ########.fr       */
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
	buf = gnl(0);
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
