/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/10/18 19:49:05 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>


//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

static int	execute_cmds(t_command_table *cmd, char **env)
{
	//printf("%s\n", cmd->cmds[0]->args[0]);
	builtins(cmd, env);
	//execve("/bin/ls", cmd->cmds[0]->args, env);
	exit(1);
}


int	executor_core(char **cmd, char**env)
{
	t_command_table	*cmd_table;
	pid_t			f;

	//print_double_str(cmd);
	cmd_table = NULL;
	create_command_table(&cmd_table, cmd);
	f = fork();
	if (f == 0)
		execute_cmds(cmd_table, env);
	else
		wait(NULL);
	return (1);
}
