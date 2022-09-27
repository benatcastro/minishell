/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/23 22:28:08 by umartin-         ###   ########.fr       */
=======
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:43:58 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/24 17:56:08 by bena             ###   ########.fr       */
>>>>>>> testing
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

# define PROMPT "\033[33mBender 🤖 > \033[0m"

int		main(int argc, char **argv, char **env);
void	builtins(char *buf, char **env);
int		ft_quote_checker(char *buf);
void	ft_export_no_arg(char **cln);
char	*ft_parser(char *str);
void	ft_list_add(t_list **args, char *str, int i);

#endif
