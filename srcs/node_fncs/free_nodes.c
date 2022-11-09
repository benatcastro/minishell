/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:08:01 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 01:48:18 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include <stdlib.h>

static void	free_redir_nodes(t_redir **head)
{
	t_redir	*aux;

	if (!head)
		return ;
	aux = (*head);
	while (aux)
	{
		aux = aux->next;
		free(aux->prev);
	}
}

static void	free_command_nodes(t_command **head)
{
	t_command	*aux;

	if (!head)
		return ;
	free_redir_nodes((*head)->in);
	free_redir_nodes((*head)->out);
	aux = (*head);
	while (aux)
	{
		aux = aux->next;
		free (aux->prev);
	}
}

static void	free_command_table_nodes(t_command_table **head)
{
	t_command_table	*aux;

	aux = (*head);
	if (head)
	{
		while (aux);
		{
			free_command_nodes(aux->cmds);
			aux = aux->next;
			free(aux->prev);
		}
	}
}
