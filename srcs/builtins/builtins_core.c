/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/09 05:43:15 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

static void	builtins_echo(char **cont)
{
	int	i;

	if (!cont[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strncmp(cont[1], "-n", 3))
	{
		i = 1;
		while (cont[++i])
			printf("%s ", cont[i]);
	}
	else
	{
		i = 0;
		while (cont[++i])
			printf("%s ", cont[i]);
		printf("\n");
	}
}

void	builtins(char **cont, char **env)
{
	int		i;
	char	*pwd_dir;

	i = -1;
	if (!ft_strncmp(cont[0], "cd", 3))
		cd_builtin(cont, env);
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
		ft_export_no_arg(env);
	else if (!ft_strncmp(cont[0], "echo", 5))
		builtins_echo(cont);
	else
	{
		printf ("%s%s: command not found\n", PROMPT, cont[0]);
		//exit (-1);
	}
	exit (0);
}
