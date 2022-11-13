/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 09:20:02 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

int	env_comparer(char *s, char *env_s)
{
	int	i;
	int	len;
	int	len_s;

	len = ft_strlen(s);
	len_s = 0;
	while (env_s[len_s] && env_s[len_s] != '=')
		len_s++;
	i = -1;
	if (len != len_s)
		return (0);
	while (env_s[++i])
		if ((env_s[i] == s[i] && env_s[i + 1]))
			return (1);
	return (0);
}

int	get_env_index(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (g_data.env[++i])
		if (!ft_strncmp(s, g_data.env[i], len))
			return (i);
	return (i);
}

char	*find_in_env(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (g_data.env[++i])
		if (!ft_strncmp(s, g_data.env[i], len))
			return (g_data.env[i]);
	return (NULL);
}

void	builtins(char **cont, char **env)
{
	int	i;

	i = -1;
	if (!ft_strncmp(cont[0], "cd", 3))
		cd_builtin(cont);
	else if (!ft_strncmp(cont[0], "env", 4))
		while (g_data.env[++i])
			printf ("%s\n", g_data.env[i]);
	else if (!ft_strncmp(cont[0], "pwd", 4))
		printf("%s\n", find_in_env("PWD"));
	else if (!ft_strncmp(cont[0], "exit", 5))
		exit_builtin();
	else if (!ft_strncmp(cont[0], "export", 7))
	{
		if (!cont[1])
			ft_export_no_arg(env);
		else
			ft_export_arg(env, cont);
	}
	else if (!ft_strncmp(cont[0], "echo", 5))
		builtins_echo(cont);
	else if (!ft_strncmp(cont[0], "unset", 6))
		unset_builtin(cont);
	exit (0);
}
