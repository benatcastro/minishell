/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:16:38 by becastro          #+#    #+#             */
/*   Updated: 2022/11/25 04:36:34 by becastro         ###   ########.fr       */
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
void	unset_builtin(char **args, int c);
int		get_env_index(char *s);
char	*find_in_env(char *s);
int		exit_builtin(char **str, int i);
void	cd_builtin(char **args);
void	builtins_echo(char **cont);
void	ft_export_no_arg(char	**env);
void	ft_export_arg(char **args);
int		export_arg_chkr(char *arg);
void	ft_doublestradd(char *arg);
#endif
