/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:16:38 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 11:31:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/******BUILTINS DEFINES******/
# define CD "cd"
# define ENV "env"
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
int		exit_builtin(void);
void	cd_builtin(char **args);
void	builtins_echo(char **cont);
void	ft_export_no_arg(char **cln);
void	ft_export_arg(char **env, char **args);
#endif
