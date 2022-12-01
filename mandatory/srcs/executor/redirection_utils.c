/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:21:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/01 21:29:06 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "signals.h"

void	doubleless_func(char *temp, int fd)
{
	char	*buf;

	if (!temp)
		exit (0);
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
		{
			write(fd, buf, ft_strlen(buf));
			write(fd, "\n", 1);
		}
	}
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
