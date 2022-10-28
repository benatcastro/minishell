/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/21 10:43:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

static void	builtins_echo(t_args *cmd)
{
	int	i;

	if (!cmd->cont[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strncmp(cmd->cont[1], "-n", 3))
	{
		i = 1;
		while (cmd->cont[++i])
			printf("%s ", cmd->cont[i]);
	}
	else
	{
		i = 0;
		while (cmd->cont[++i])
			printf("%s ", cmd->cont[i]);
		printf("\n");
	}
}

void	builtins(t_args **cmd, char **env)
{
	t_args	*temp;
	int		i;
	char	*pwd_dir;

	temp = *cmd;
	i = -1;
	if (!ft_strncmp(temp->cont[0], "env", 4))
	{
		while (env[++i])
			printf ("%s\n", env[i]);
	}
	else if (!ft_strncmp(temp->cont[0], "pwd", 4))
	{
		pwd_dir = getcwd(NULL, 0);
		printf("%s\n", pwd_dir);
		free(pwd_dir);
	}
	else if (!ft_strncmp(temp->cont[0], "exit", 5))
	{
		printf ("exit\n");
		exit (0);
	}
	else if (!ft_strncmp(temp->cont[0], "export", 7))
		ft_export_no_arg(env);
	else if (!ft_strncmp(temp->cont[0], "echo", 5))
		builtins_echo(temp);
	else
		printf ("%s%s: command not found\n", PROMPT, temp->cont[0]);
}
