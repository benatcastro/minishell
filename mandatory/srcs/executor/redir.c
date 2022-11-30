/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:38:01 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 18:18:53 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"

void	redirection_in(t_command **cmd_node, char	**args)
{
	char	**temp;
	int		i;

	i = -1;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
		{
			temp = ft_calloc(3, sizeof(char *));
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			ft_rediradd_back(&(*cmd_node)->in, create_redir_node(temp));
		}
	}
}

void	redirection_out(t_command **cmd_node, char	**args)
{
	char		**temp;
	int			i;

	i = -1;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER)))
		{
			temp = malloc(sizeof(char *) * 3);
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			ft_rediradd_back(&(*cmd_node)->out, create_redir_node(temp));
		}
	}
}

void	redirection_ag_var(char	**args, int *a, int *i)
{
	if ((ft_strcmp(args[(*i)], GREATER))
		|| (ft_strcmp(args[(*i)], DOUBLEGREATER))
		|| (ft_strcmp(args[(*i)], LESS))
		|| (ft_strcmp(args[(*i)], DOUBLELESS)))
		(*i)++;
	else
		(*a)++;
}

void	redirection_ag(t_command **cmd_head, char	**args)
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
		(*cmd_head)->args = NULL;
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
	(*cmd_head)->args = temp;
}

void	redir_link(t_command **cmd_head, char **args)
{
	redirection_in(cmd_head, args);
	redirection_out(cmd_head, args);
	redirection_ag(cmd_head, args);
}
