/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:07:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 18:13:24 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

extern t_data	g_data;

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
	{
		if (env_s[i] == s[i] && (i == (len - 1)))
			return (1);
		else if (i == len - 1)
			break ;
	}
	return (0);
}

int	env_index(char *s)
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

	if (!s)
		return (NULL);
	i = -1;
	while (g_data.env[++i])
		if (env_comparer(s, g_data.env[i]))
			return (g_data.env[i]);
	return (NULL);
}

void	builtins(char **cont)
{
	int		i;

	i = -1;
	if (!ft_strncmp(cont[0], "cd", 3))
		exit(0);
	else if (!ft_strncmp(cont[0], "env", 4))
		env_printer();
	else if (!ft_strncmp(cont[0], "pwd", 4))
		printf("%s\n", getcwd(NULL, 0));
	else if (!ft_strncmp(cont[0], "exit", 5))
		exit (0);
	else if (!ft_strncmp(cont[0], "echo", 5))
		builtins_echo(cont);
	else if (!ft_strncmp(cont[0], "export", 7))
	{
		if (cont[1] == NULL)
			ft_export_no_arg(ft_doublestrdup(g_data.env));
		else
			exit(0);
	}
	else if (!ft_strncmp(cont[0], "unset", 6))
		exit(0);
	exit (0);
}
