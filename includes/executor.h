/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/11/13 05:22:01 by becastro         ###   ########.fr       */
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
	struct s_redir			*out;
	struct s_redir			*in;
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
	unsigned int			exit_status;
	struct s_command		**cmds;
	struct s_command_table	*prev;
	struct s_command_table	*next;
}	t_command_table;

//////////////////FNCS////////////////////////////

int				executor_core(char **cmd, char**env);
void			fill_cmd(t_command *node, char **cmds);
t_command_table	**create_command_table(t_command_table **head, char **cmds);
char			*ft_strdup_n_rem(const char *s1);
void			redir_link(t_command **cmd_head, char **args);
void			execute_cmds(char **args, char **env);
void			fd_closer(int fd[2][2]);
void			doubleless_func(char *temp, int fd);
void			redirection_core(t_command *temp, char **env);

///////////////////////UTILS//////////////////////////

int				builtin_checker(char **args);
char			*env_path_maker(char *val, char **env, int *i);
char			*bin_path_finder(char **args, char **env);
//static void		bin_executor(char **args, char **env);
void			execute_cmds(char **args, char **env);
void			exec_morepipes(t_command **cmd_table,
					char **env, pid_t pid[3], int i[2]);
int				first_pipe_op(t_command *temp,
					int fd[2], char **env, int *pid);
int				second_pipe_op(t_command *temp,
					int fd[2], char **env, int *pid);

#endif



	// pid[2] = fork();
	// if (pid[2] == 0)
	// 	return (redir_link(&temp, temp->args), dup2(fd[1][0], STDIN_FILENO),
	// 			fd_closer (fd), redirection_core(temp, env), 0);
	// fd_closer(fd);
	// return (0);
