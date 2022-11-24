/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:16:38 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 01:43:58 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/******BUILTINS DEFINES******/
# define CD "cd"
# define PWD "pwd"
# define EXIT "exit"
# define EXPORT "export"
# define ECHO "echo"
# define UNSET "unset"

int		env_comparer(char *s, char *env_s);
void	rebuild_env(char *var);
void	unset_builtin(char **args);
int		get_env_index(char *s);
char	*find_in_env(char *s);
int		exit_builtin(char **str);
void	cd_builtin(char **args);
void	builtins_echo(char **cont);
void	ft_export_no_arg(char	**env);
void	ft_export_arg(char **args);
int		export_arg_chkr(char *arg);
void	ft_doublestradd(char *arg);
#endif
