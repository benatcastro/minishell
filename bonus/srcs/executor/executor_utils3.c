/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:34:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/12 16:09:35 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

void	paren_checker_ut2(char **lex, int *i, int *c)
{
	while (lex[0][(*i)])
	{
		if (lex[0][(*i)] == 40)
			(*c)++;
		if (lex[0][(*i)] == 41)
		{
			if ((*c) == 0)
				break ;
			else
				(*c)--;
		}
		(*i)++;
	}
}

void	paren_checker_ut(char **lex, int i, int c)
{
	i = -1;
	while (lex[++i])
	{
		if (lex[i][0] == 40 && (lex[i + 1] != NULL
						|| (i != 0 && lex[i - 1] != NULL)))
		{
			printerr("%ssyntax error: unexpected token\n", PROMPT_ERR);
			exit(1);
		}
	}
	i = 1;
	if (lex[0][0] == 40)
	{
		paren_checker_ut2(lex, &i, &c);
		if (lex[0][i + 1] != 0)
		{
			printerr("%ssyntax error: unexpected token\n", PROMPT_ERR);
			exit(1);
		}
	}
}

char	**paren_checker(char **lex)
{
	int		i;
	int		c;
	char	**rtn;

	i = 0;
	c = 0;
	if (!lex || !lex[0])
		return (NULL);
	paren_checker_ut(lex, i, c);
	if (lex[0][0] == 40)
	{
		rtn = ft_calloc(4, sizeof(char *));
		rtn[0] = ft_strjoin(g_data.shell_path, "/minishell_bonus");
		rtn[1] = ft_strdup("-c");
		rtn[2] = ft_strdup(expand_trimmer(lex[0]));
		return (rtn);
	}
	return (lex);
}
