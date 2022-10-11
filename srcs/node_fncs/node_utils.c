/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:20:33 by becastro          #+#    #+#             */
/*   Updated: 2022/10/05 16:48:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "nodes.h"
#include "executor.h"
#include "stdio.h"

void	print_double_str_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("\t(%s)\n", str[i]);
}

void	print_cmd(t_command **cmd_head)
{
	t_command	*aux;

	aux = (*cmd_head);
	while (aux)
	{
		printf("=========CMDS=========\n");
		printf("\tCmd key: (%d)\n", aux->key);
		printf("\tCmd: (%s)\n", aux->cmd);
		printf("\tArgs:\n");
		print_double_str_tab(aux->args);
		printf("\tPrev (%p) Current (%p) Next (%p)\n", aux->prev, aux, aux->next);
		aux = aux->next;
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
		print_cmd(aux->cmds);
		aux = aux->next;
	}
}
