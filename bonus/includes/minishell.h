/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/10 14:31:31 by becastro         ###   ########.fr       */
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

# define PROMPT "BASHado-2.0 > "
# define PROMPT_ERR "BASHado: "

typedef struct s_data
{
	int		ms_pid;
	int		sub_pid;
	int		exit_val;
	char	*shell_path;
	char	**env;
}	t_data;

t_data	g_data;

char	*reverse_search(const char *haystack, const char *needle);
char	**ft_doublestrjoin(char **s1, char **s2);
char	**str_to_double(char *str);
void	builtins(char **cont);
int		ft_quote_checker(char *buf);
int		parser_paren_error_chk(char *str);
void	print_double_str(char **str);
void	print_double_str(char **str);
char	**ft_split_exec(char const *s, char c);
int		global_error_chkr(char	**lex);
char	*env_finder(char *str);
void	get_exit_status(void);
char	*expand_trimmer(char	*str);
void	glob_err_chckr_error(char *buf, char **lex);

#endif
