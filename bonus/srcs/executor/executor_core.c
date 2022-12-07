/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/12/07 17:57:48 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

void	ft_allocator(t_shell *shell, t_command *temp)
{
	int	i;

	i = 0;
	g_data.sub_pid = 1;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	shell->np = i;
	pipe(shell->fd[0]);
	pipe(shell->fd[1]);
}

void	pipe_core(t_command **cmd_table)
{
	t_command		*temp;
	int				i[2];

	temp = (*cmd_table);
	i[0] = 1;
	i[1] = -1;
	temp = (*cmd_table);
	while (temp->next)
	{
		temp = temp->next;
		i[0]++;
	}
	exec_morepipes(cmd_table);
}

static t_command_table	*separator_checker(t_command_table *node)
{
	if ((node && node->next) && node->next->separator != EMPTY)
	{
		if (node->next
			&& (node->next->separator == AND || node->separator == AND))
		{
			pipe_core(node->cmds);
			if (g_data.exit_val != 0)
				node = node->next->next;
			else
				node = node->next;
		}
		if (node && node->next
			&& (node->next->separator == OR || node->separator == OR))
		{
			pipe_core(node->cmds);
			if (g_data.exit_val == 0)
				node = node->next->next;
			else
				node = node->next;
		}
	}
	return (node);
}

static void	execution_loop(t_command_table **table_head)
{
	t_command_table	*aux;

	aux = (*table_head);
	if (!aux->next)
		return (pipe_core(aux->cmds));
	if (!aux->next->next)
	{
		aux = separator_checker(aux);
		while (aux)
		{
			pipe_core(aux->cmds);
			if (aux)
				aux = aux->next;
		}
		return ;
	}
	while (aux->next)
		aux = separator_checker(aux);
}

int	executor_core(char **cmd)
{
	t_command_table	*table_head;

	table_head = NULL;
	create_command_table(&table_head, cmd);
	execution_loop(&table_head);
	ft_doublefree(cmd);
	free_command_table_nodes(&table_head);
	return (1);
}
