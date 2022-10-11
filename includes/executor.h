/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/10/05 16:09:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include <unistd.h>

# define AMPERSAND "<AMPERSAND>"
# define DOUBLEAMPERSAND "<DOUBLEAMPERSAND>"

# define PIPE "<PIPE>"
# define DOUBLEPIPE "<DOUBLEPIPE>"

# define GREATER "<GREATER>"
# define DOUBLEGREATER "<DOUBLEGREATER>"

# define LESS "<LESS>"
# define DOUBLELESS "<DOUBLELESS>"

# define SEMICOLON "<SEMICOLON>"

typedef struct s_command
{
	unsigned int		key;
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
	unsigned int			key;
	struct s_command		**cmds;
	struct s_command_table	*prev;
	struct s_command_table	*next;
}	t_command_table;

//////////////////FNCS////////////////////////////

int				executor_core(char **cmd, char**env);
void			fill_cmd(t_command *node, char **cmds);
t_command_table	**create_command_table(t_command_table **head, char **cmds);

#endif
