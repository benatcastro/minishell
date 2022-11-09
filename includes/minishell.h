/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/09 14:45:08 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

# define PROMPT "\033[33mBASHado 🤖 > \033[0m"

int		main(int argc, char **argv, char **env);
void	builtins(char **cont, char **env);
int		ft_quote_checker(char *buf);
void	print_double_str(char **str);
void	ft_export_no_arg(char **cln);
int		signals_core(void);
void	print_double_str(char **str);
char	**ft_split_exec(char const *s, char c);
int		global_error_chkr(char	**lex);

#endif
