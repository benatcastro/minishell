/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/23 23:25:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//int fdr = open("error", O_CREAT | O_WRONLY | O_TRUNC);

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "executor.h"

# define PROMPT "BASHado2.0 > "

typedef struct s_data
{
	int		ms_pid;
	int		sub_pid;
	int		exit_val;
	char	**env;
}	t_data;

// t_data	g_data;

void	builtins(char **cont);
int		ft_quote_checker(char *buf);
void	print_double_str(char **str);
int		signals_core(void);
void	print_double_str(char **str);
char	**ft_split_exec(char const *s, char c);
int		global_error_chkr(char	**lex);
char	*env_finder(char *str);
void	get_exit_status(void);

#endif
