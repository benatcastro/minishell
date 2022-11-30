/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:34:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 19:56:42 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

void	paren_checker_ut(char **lex, int i)
{
	i = -1;
	while (lex[++i])
	{
		if (lex[i][0] == 40 && (lex[i + 1] != NULL
						|| (i != 0 && lex[i - 1] != NULL)))
		{
			write(2, "BASHado: syntax error: unexpected token\n", 40);
			exit(1);
		}
	}
	i = 1;
	if (lex[0][0] == 40)
	{
		while (lex[0][i] != 41)
			i++;
		if (lex[0][i + 1] != 0)
		{
			write(2, "BASHado: syntax error: unexpected token\n", 40);
			exit(1);
		}
	}
}

char	**paren_checker(char **lex)
{
	int		i;
	char	**rtn;

	i = 0;
	if (!lex || !lex[0])
		return (NULL);
	paren_checker_ut(lex, i);
	if (lex[0][0] == 40)
	{
		rtn = ft_calloc(3, sizeof(char *));
		rtn[0] = ft_strjoin(g_data.shell_path, "/minishell");
		rtn[1] = ft_strdup("-c");
		rtn[2] = ft_strdup(expand_trimmer(lex[0]));
		return (rtn);
	}
	return (lex);
}
