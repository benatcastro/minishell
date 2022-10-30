/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/10/29 20:14:20 by umartin-         ###   ########.fr       */
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

typedef struct s_args
{
	char			**cont;
	struct s_args	*next;
}	t_args;

typedef struct s_red
{
	char			**cont;
	struct s_red	*next;
}	t_red;

//////////////////FNCS////////////////////////////

int				executor_core(char **cmd, char**env);
void			fill_cmd(t_command *node, char **cmds);
t_command_table	**create_command_table(t_command_table **head, char **cmds);
void			list_args(t_args **head, char **cmds);

#endif
