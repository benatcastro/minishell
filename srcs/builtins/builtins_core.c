/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/09 09:38:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

char	*find_in_env(char *s, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (env[i][++j] == s[j])
		{
			if (j = ft_strlen(s));
				return (env[i]);
		}
		printf("i = %d\n", i);
		printf("test\n");
	}
	return (env[i]);
}

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
	if (!ft_strncmp(cont[0], CD, 3))
		cd_builtin(cont, env);
	else if (!ft_strncmp(cont[0], ENV, 4))
	{
		while (env[++i])
			printf ("%s\n", env[i]);
	}
	else if (!ft_strncmp(cont[0], PWD, 4))
		pwd_builtin(env);
	else if (!ft_strncmp(cont[0], EXIT, 5))
	{
		printf ("exit\n");
		exit (0);
	}
	else if (!ft_strncmp(cont[0], EXPORT, 7))
		ft_export_no_arg(env);
	else if (!ft_strncmp(cont[0], ECHO, 5))
		builtins_echo(cont);
	else
	{
		printf ("%s%s: command not found\n", PROMPT, cont[0]);
		//exit (-1);
	}
	exit (0);
}
