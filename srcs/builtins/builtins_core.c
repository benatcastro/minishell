/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/12 15:39:01 by umartin-         ###   ########.fr       */
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

void	ft_doublestradd(char **str, char *arg)
{
	char	**aux;
	int		i;

	i = ft_doublestrlen(str);
	str[i] = arg;
	str[i + 1] = 0;
}

int	export_arg_chkr(char *arg)
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
	return (1);
}

void	ft_doubleprint_err(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (str[i])
	{
		write (2, str[i], ft_strlen(str[i]));
		write (2, "\n", 1);
		i++;
	}
}

void	ft_export_arg(char **env, char **args)
{
	int	i;

	i = 0;
	while (args[++i])
		if (!export_arg_chkr(args[i]))
			exit (0);
	//ft_doubleprint_err(env);
	i = 0;
	while (args[++i])
		ft_doublestradd(env, args[i]);
	ft_doubleprint_err(env);
	return ;
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
