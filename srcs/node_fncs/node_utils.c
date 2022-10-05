/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:20:33 by becastro          #+#    #+#             */
/*   Updated: 2022/10/05 12:48:18 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "nodes.h"
#include "executor.h"
#include "stdio.h"

void	print_cmd(t_command **cmd_head)
{
	t_command	*aux;

	aux = (*cmd_head);
	while (aux)
	{
		printf("\tCmd key: (%d)\n", aux->key);
		printf("\tCmd: (%s)\n", aux->cmd);
		printf("\tArgs:\n");
		print_double_str(aux->args);
		printf("\tPrev (%p) Current (%p) Next (%p)\n", aux->prev, aux, aux->next);
	}
}

void	print_table(t_command_table **table_head)
{
	t_command_table	*aux;

	aux = (*table_head);
	while (aux)
	{
		printf("=====================\n");
		printf("Table Key: (%d)\n", aux->key);
		printf("Prev (%p) Current (%p) Next (%p)\n", aux->prev, aux, aux->next);
		printf("=========CMDS=========\n");
		print_cmd(aux->cmds);
		aux = aux->next;
	}
}
