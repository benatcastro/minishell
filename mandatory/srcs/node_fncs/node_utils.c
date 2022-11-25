/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:20:33 by becastro          #+#    #+#             */
/*   Updated: 2022/11/25 05:53:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "nodes.h"
#include "executor.h"
#include "stdio.h"

void	print_double_str_tab(char **str)
{
	int	i;

	if (!str || (!*str))
		return ;
	i = -1;
	while (str[++i])
		printf("\t(%s)\n", str[i]);
}

void	print_redir(t_redir	**redir_head)
{
	t_redir	*aux;

	if ((!*redir_head))
		return ;
	aux = (*redir_head);
	while (aux)
	{
		print_double_str_tab(aux->content);
		aux = aux->next;
	}
}

void	print_cmd(t_command **cmd_head)
{
	t_command	*aux;

	aux = (*cmd_head);
	while (aux)
	{
		printf("=========CMDS=========\n");
		printf("\tCmd key: (%d)\n", aux->key);
		printf("\tArgs:\n");
		print_double_str_tab(aux->args);
		printf("\tIN:\n");
		print_redir(&aux->in);
		printf("\tOUT:\n");
		print_redir(&aux->out);
		printf("\t---------------------------------------------------\n");
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
		if (aux->separator == EMPTY)
			printf("Separator: No Separator\n");
		if (aux->separator == AND)
			printf("Separator: AND\n");
		if (aux->separator == OR)
			printf("Separator: OR\n");
		printf("Prev (%p) Current (%p) Next (%p)\n", aux->prev, aux, aux->next);
		print_cmd(aux->cmds);
		aux = aux->next;
	}
}
