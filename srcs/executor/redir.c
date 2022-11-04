/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:38:01 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/04 20:28:59 by umartin-         ###   ########.fr       */
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
			temp = malloc(sizeof(char *) * 3);
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			//printf("===REDIR IN===\n");
			//print_double_str(temp);

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
			//printf("===REDIR OUT===\n");
			//print_double_str(temp);
			ft_rediradd_back(&(*cmd_node)->out, create_redir_node(temp));
		}
	}
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
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER))
			|| (ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
			i++;
		else
			a++;
	}
	temp = ft_calloc(a + 1, sizeof(char **));
	temp[a + 1] = NULL;
	//printf("A = %d\n", a);
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
	// printf("temp\n");
	// print_double_str(temp);
	// printf("cmd args\n");
	// print_double_str((*cmd_head)->args);
	(*cmd_head)->args = temp;
	// printf("I = %d\n", i);
	// printf("E = %d\n", e);
	// temp[e + 2] = NULL;
}

void	redir_link(t_command **cmd_head, char **args)
{
	// printf("===REDIR ARGS===\n");
	// print_double_str(args);
	redirection_in(cmd_head, args);
	redirection_out(cmd_head, args);
	redirection_ag(cmd_head, args);
	//exit(0);
}
