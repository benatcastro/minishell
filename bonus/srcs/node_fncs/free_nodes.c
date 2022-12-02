/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:08:01 by becastro          #+#    #+#             */
/*   Updated: 2022/11/25 05:15:45 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

static void	free_redir_nodes(t_redir **head)
{
	t_redir	*aux;

	if (!(*head))
		return ;
	while (head)
	{
		aux = (*head);
		if ((*head)->next)
			(*head) = (*head)->next;
		free(aux);
	}
}

static void	free_command_nodes(t_command **head)
{
	t_command	*aux;

	if (!(*head))
		return ;
	free_redir_nodes(&(*head)->in);
	free_redir_nodes(&(*head)->out);
	while (*head)
	{
		aux = (*head);
		free((*head)->args);
		free(aux->out);
		free(aux->in);
		(*head) = (*head)->next;
		free(aux);
	}
	free((*head));
}

void	free_command_table_nodes(t_command_table **head)
{
	t_command_table	*aux;

	if (!(*head))
		return ;
	aux = (*head);
	if (head)
	{
		while (*head)
		{
			aux = (*head);
			free_command_nodes(aux->cmds);
			free(aux->cmds);
			(*head) = (*head)->next;
			free(aux);
		}
	}
}
