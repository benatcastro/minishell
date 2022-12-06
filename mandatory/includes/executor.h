/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:00:02 by bena              #+#    #+#             */
/*   Updated: 2022/12/06 17:55:49 by umartin-         ###   ########.fr       */
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

typedef struct s_shell
{
	pid_t	pid;
	int		np;
	int		fd[2][2];

}			t_shell;

//////////////////FNCS////////////////////////////

int				executor_core(char **cmd);
void			fill_cmd(t_command *node, char **cmds);
t_command_table	**create_command_table(t_command_table **head, char **cmds);
char			*ft_strdup_n_rem(const char *s1);
void			redir_link(t_command **cmd_head, char **args);
void			fd_closer(int fd[2][2]);
void			doubleless_func(char *temp, int fd);
void			redirection_core(t_command *temp);

///////////////////////UTILS//////////////////////////

int				builtin_checker(char **args);
char			*env_path_maker(char *val, int *i);
char			*bin_path_finder(char **args, int *exit);
//static void		bin_executor(char **args);
void			execute_cmds(char **args);
void			exec_morepipes(t_command **cmd_table);
int				first_pipe_op(t_command *temp,
					int fd[2], int *pid);
int				second_pipe_op(t_command *temp,
					int fd[2], int *pid);
char			*gnl(int fd);
void			doubleless_func(char *temp, int fd);
void			fd_closer_shell(t_shell *shell);
void			ft_allocator(t_shell *shell, t_command *temp);
void			redirection_ag_var(char	**args, int *a, int *i);
char			**redir_remover(char **args);
void			heredoc_utils(char *str, int fd);

///////////////////////REDIS//////////////////////////////
void			in_redirection(t_redir *t, int fd[2]);
void			first_pipe_only(int *pid, t_command *temp,
					int fd[2][2], int f[2]);
void			first_pipe_more(int *pid, t_command *temp,
					int fd[2][2], int f[2]);
void			env_printer(void);

#endif

	// pid[2] = fork();
	// if (pid[2] == 0)
	// 	return (redir_link(&temp, temp->args), dup2(fd[1][0], STDIN_FILENO),
	// 			fd_closer (fd), redirection_core(temp), 0);
	// fd_closer(fd);
	// return (0);
