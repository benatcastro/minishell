/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 05:50:26 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"


void	builtins(char **cont, char **env)
{
	int		i;
	char	*pwd_dir;

	i = -1;
	if (!ft_strncmp(cont[0], "cd", 3))
		cd_builtin(cont);
	else if (!ft_strncmp(cont[0], "env", 4))
	{
		while (env[++i])
			printf ("%s\n", env[i]);
	}
	else if (!ft_strncmp(cont[0], "pwd", 4))
	{
		pwd_dir = getcwd(NULL, 0);
		printf("%s\n", pwd_dir);
		free(pwd_dir);
	}
	else if (!ft_strncmp(cont[0], "exit", 5))
	{
		printf ("exit\n");
		exit (0);
	}
	else if (!ft_strncmp(cont[0], "export", 7))
	{
		if (!cont[1])
			ft_export_no_arg(env);
		else
			ft_export_arg(env, cont);
	}
	else if (!ft_strncmp(cont[0], "echo", 5))
		builtins_echo(cont);
	exit (0);
}
