/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/12 03:35:25 by umartin-         ###   ########.fr       */
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

char	**ft_doublestradd(char **str, char *arg)
{
	char	**result;
	int		i;

	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_doublestrlen(str) + 2));
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
		result[i] = ft_strdup(str[i]);
	result[i] = ft_strdup(arg);
	result[i * 1] = 0;
	ft_doublefree(str);
	free (arg);
	return (result);
}

int		export_arg_chkr(char *arg)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (arg[++i])
		if (arg[i] == '=')
			cont++;
	if (cont == 0)
	{
		write (2, "Invalid export argument: ", 25);
		write (2, arg, ft_strlen(arg));
		write (2, "\n", 1);
		return (-1);
	}
	return (0);
}

void	ft_export_arg(char **env, char **args)
{
	int	i;

	i = 0;
	while (args[++i])
		if (!export_arg_chkr(args[i]))
			exit (0);
	i = 0;
	while (args[++i])
		env = ft_doublestradd(env, args[i]);
	exit (0);
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
		if (!cont[1])
			ft_export_no_arg(env);
		else
			ft_export_arg(env, cont);
	else if (!ft_strncmp(cont[0], "echo", 5))
		builtins_echo(cont);
	exit (0);
}
