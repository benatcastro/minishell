/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/12/12 17:18:01 by umartin-         ###   ########.fr       */
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

static int	exec_check(t_command **cmds)
{
	if (g_data.exit_val == 0)
		pipe_core(cmds);
	else
		return (1);
	return (0);
}

static void	execution_loop(t_command_table **table_head)
{
	t_command_table	*aux;

	aux = (*table_head);
	pipe_core(aux->cmds);
	if (aux->next != NULL)
		aux = aux->next;
	else
		return ;
	while (aux != NULL)
	{
		if (aux->separator == AND)
			if (exec_check(aux->cmds))
				break ;
		if (aux->separator == OR)
		{
			if (g_data.exit_val == 0)
				break ;
			else
				pipe_core(aux->cmds);
		}
		aux = aux->next;
	}
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
