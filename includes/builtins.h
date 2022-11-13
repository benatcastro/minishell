/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:16:38 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 05:49:41 by becastro         ###   ########.fr       */
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

int		exit_builtin(void);
void	cd_builtin(char **args);
void	builtins_echo(char **cont);
void	ft_export_no_arg(char **cln);
void	ft_export_arg(char **env, char **args);
#endif
