/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:58:04 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/21 09:19:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"

static char	*lex_first_spc_rm(char *str)
{
	int		i;
	int		e;
	int		u;
	char	*rtn;

	i = 0;
	e = (ft_strlen(str) - 1);
	u = 0;
	if (str[e] != 32)
		e = (ft_strlen(str));
	else if (str[e] == 32)
		while (str[e] == 32)
			e--;
	while (str[i] == 32)
		i++;
	rtn = ft_calloc(sizeof(char),
			(ft_strlen(str) - i - (ft_strlen(str) - e - 1) + 1));
	while (i <= e)
		rtn[u++] = str[i++];
	rtn[u + 1] = 0;
	return (rtn);
}

static int	replace_for_keywords(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "&&"))
			str[i] = ft_str_replace(str[i], DOUBLEAMPERSAND);
		else if (ft_strcmp(str[i], "|"))
			str[i] = ft_str_replace(str[i], PIPE);
		else if (ft_strcmp(str[i], "||"))
			str[i] = ft_str_replace(str[i], DOUBLEPIPE);
		else if (ft_strcmp(str[i], ">"))
			str[i] = ft_str_replace(str[i], GREATER);
		else if (ft_strcmp(str[i], ">>"))
			str[i] = ft_str_replace(str[i], DOUBLEGREATER);
		else if (ft_strcmp(str[i], "<"))
			str[i] = ft_str_replace(str[i], LESS);
		else if (ft_strcmp(str[i], "<<"))
			str[i] = ft_str_replace(str[i], DOUBLELESS);
		else if (ft_strcmp(str[i], ";"))
			str[i] = ft_str_replace(str[i], SEMICOLON);
	}
	return (1);
}

char	**lex_core(char *str)
{
	int		i;
	char	**rtn;

	i = -1;
	str = lex_first_spc_rm(str);
	if (parser_quote_error_chk(str))
		exit (0);
	rtn = malloc(sizeof(char *) * (lex_memory_splitter(str)) + 1);
	rtn = lex_splitter(str, rtn);
	replace_for_keywords(rtn);
	return (rtn);
}
