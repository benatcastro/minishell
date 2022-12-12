/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_error_chkcr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:51:00 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/12 16:27:53 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "signals.h"
#include "builtins.h"
#include <errno.h>

void	glob_err_chckr_error(char *buf, char **lex)
{
	printerr("%ssyntax error\n", PROMPT_ERR);
	g_data.exit_val = 258;
	free (buf);
	ft_doublefree(lex);
}

int	global_error_chkr_ut(char	**lex, int i)
{
	if (ft_strcmp(lex[0], DOUBLEAMPERSAND) || ft_strcmp(lex[0], DOUBLEPIPE))
		return (-1);
	if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
		|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
		if ((lex[i + 1] && ft_strcmp(lex[i + 1], GREATER))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLEGREATER))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], LESS))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLELESS))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], PIPE))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLEPIPE)))
			return (-1);
	if ((ft_strcmp(lex[i], PIPE)) || (ft_strcmp(lex[i], DOUBLEPIPE)
			|| (ft_strcmp(lex[i], DOUBLEAMPERSAND))))
		if (!lex[i + 1] || (ft_strcmp(lex[i + 1], PIPE))
			|| (ft_strcmp(lex[i + 1], DOUBLEPIPE)))
			return (-1);
	return (0);
}

int	global_error_chkr_ut2(char	**lex, int i)
{
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if (lex[i + 1] == NULL)
				return (-1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], DOUBLEAMPERSAND))
			|| (ft_strcmp(lex[i], DOUBLEPIPE)))
			if ((ft_strcmp(lex[i + 1], DOUBLEAMPERSAND))
				|| (ft_strcmp(lex[i + 1], DOUBLEPIPE)))
				return (-1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], SEMICOLON)) || (ft_strcmp(lex[i], "ASCII92")))
			return (-1);
	return (0);
}

int	global_error_chkr(char	**lex)
{
	int	i;

	i = -1;
	if (!lex || lex[0] == NULL)
		return (-1);
	if (ft_strcmp(lex[0], "<PIPE>"))
		return (1);
	i = -1;
	while (lex[++i])
		if (global_error_chkr_ut(lex, i) == -1)
			return (-1);
	if (global_error_chkr_ut2(lex, i) == -1)
		return (-1);
	i = -1;
	while (lex[++i])
		if ((lex[i][0] == '<' || lex[i][0] == '>' || lex[i][0] == '|')
			&& (lex[i][1] == '<' || lex[i][1] == '>' || lex[i][1] == '|'))
			return (-1);
	if (ft_strcmp (lex[ft_doublestrlen(lex) - 1], PIPE))
		return (1);
	return (0);
}
