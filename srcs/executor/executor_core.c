/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/09/30 13:34:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct
int	executor_core(char **cmd, char**env)
{
	t_command_table	**cmd_table;

	cmd_table = create_command_table(cmd);
	return (1);
}