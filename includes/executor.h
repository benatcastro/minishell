/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/09/30 13:58:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include <unistd.h>

# define DOUBLEPIPE "<DOUBLEPIPE>"
# define DOUBLEAMPERSAND "<DOUBLEAMPERSAND>"

typedef struct s_command
{
	char				*cmd;
	char				**args;
	char				*cmd_input;
	int					out_fd;
	int					exit_value;
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

/**
 * @brief
 * cmds -> head to the list of commands
 *
 */
typedef struct s_command_table
{
	struct s_command		**cmds;
	struct s_command_table	*prev;
	struct s_command_table	*next;
}	t_command_table;

//////////////////FNCS////////////////////////////

int				executor_core(char **cmd, char**env);
t_command_table	**create_command_table(char **cmds);

#endif