/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/11/14 19:35:23 by umartin-         ###   ########.fr       */
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

void	fd_closer(int fd[2][2])
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (close (fd[0][i]))
			return ;
		if (close (fd[1][i]))
			return ;
		i++;
	}
}

void	pipe_core(t_command **cmd_table)
{
	t_command		*temp;
	int				i[2];
	pid_t			pid[3];

	i[0] = 1;
	temp = (*cmd_table);
	while (temp->next)
	{
		temp = temp->next;
		i[0]++;
	}
	exec_morepipes(cmd_table, pid, i);
}

int	executor_core(char **cmd)
{
	t_command_table	*table_head;
	t_command_table	*aux;

	table_head = NULL;
	create_command_table(&table_head, cmd);
	aux = table_head;
	while (aux)
	{
		pipe_core(aux->cmds);
		aux = aux->next;
	}
	//free_command_table_nodes(&table_head);
	// print_table(&table_head);
	return (1);
}
