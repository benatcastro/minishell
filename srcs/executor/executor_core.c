/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/10/05 12:52:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct
int	executor_core(char **cmd, char**env)
{
	t_command_table	*cmd_table;

	printf("===EXECUTOR INPUT===\n");
	print_double_str(cmd);
	cmd_table = NULL;
	create_command_table(&cmd_table, cmd);
	printf("===EXECUTOR ENDS===\n");
	return (1);
}
