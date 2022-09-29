/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/29 14:02:07 by becastro         ###   ########.fr       */
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
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "\033[33mBASHado 🤖 > \033[0m"

int		main(int argc, char **argv, char **env);
void	builtins(char *buf, char **env);
int		ft_quote_checker(char *buf);
void	print_double_str(char **str);
void	ft_export_no_arg(char **cln);
int		signals_core(void);
void	print_double_str(char **str);

#endif
