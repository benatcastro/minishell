/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/11/04 06:18:06 by bena             ###   ########.fr       */
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

/******BUILTINS DEFINES******/

# define ENV "env"
# define PWD "pwd"
# define EXIT "exit"
# define EXPORT "export"
# define ECHO "echo"

typedef struct s_redir
{
	char				**content;
	struct s_redir		*next;
	struct s_redir		*prev;
}	t_redir;
typedef struct s_command
{
	unsigned int			key;
	char					**args;
	struct s_redir			**out;
	struct s_redir			**in;
	struct s_command		*prev;
	struct s_command		*next;
}	t_command;

/**
 * @brief
 * cmds -> head to the list of commands
 *
 */
typedef struct s_command_table
{
	unsigned int			key;
	unsigned int			exit_status; //se utilizara para el bonus
	char					**f_cmd;
	struct s_command		**cmds;
	struct s_command_table	*prev;
	struct s_command_table	*next;
}	t_command_table;

typedef struct s_redirections
{
	struct s_red			*in;
	struct s_red			*out;
	struct s_red			*ag;
	struct s_redirections	*prev;
	struct s_redirections	*next;
}	t_redirections;



//////////////////FNCS////////////////////////////

int				executor_core(char **cmd, char**env);
void			fill_cmd(t_command *node, char **cmds);
t_command_table	**create_command_table(t_command_table **head, char **cmds);
//void			list_args(t_args **head, char **cmds);
void			redir_link(t_command **cmd_head, char **args);

#endif
