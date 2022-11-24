/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:58:04 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 22:25:25 by umartin-         ###   ########.fr       */
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
	if (i == (int)ft_strlen(str))
		return (NULL);
	rtn = ft_calloc(sizeof(char),
			(ft_strlen(str) - i - (ft_strlen(str) - e - 1) + 1));
	while (i <= e)
		rtn[u++] = str[i++];
	rtn[u] = 0;
	return (rtn);
}

char	**temp_maker(char *rtn)
{
	char	**temp;

	if (rtn[0] == '|')
		temp = temp_utis_pipe(rtn);
	if (rtn[0] == '<' && rtn[1] != '<')
		temp = temp_utis_less(rtn);
	if (rtn[0] == '<' && rtn[1] == '<')
		temp = temp_utis_doubleless(rtn);
	if (rtn[0] == '>' && rtn[1] != '>')
		temp = temp_utis_greater(rtn);
	if (rtn[0] == '>' && rtn[1] == '>')
		temp = temp_utis_doublegreater(rtn);
	return (temp);
}

void	pipe_redir_rep_mem(char **rtn, int *i, int *c)
{
	(*i) = -1;
	(*c) = 0;
	while (rtn[++(*i)])
	{
		if ((rtn[(*i)][0] == '|' && rtn[(*i)][1])
			|| (rtn[(*i)][0] == '>' && rtn[(*i)][1] == '>' && rtn[(*i)][2])
			|| (rtn[(*i)][0] == '>' && rtn[(*i)][1] != '>' && rtn[(*i)][1])
			|| (rtn[(*i)][0] == '<' && rtn[(*i)][1] == '<' && rtn[(*i)][2])
			|| (rtn[(*i)][0] == '<' && rtn[(*i)][1] != '<' && rtn[(*i)][1]))
			(*c) += 2;
		else
			(*c)++;
	}
	(*i) = -1;
}

char	**pipe_redir_replacer(char **rtn)
{
	int		i;
	int		c;
	char	**fin;
	char	**temp;

	pipe_redir_rep_mem(rtn, &i, &c);
	fin = ft_calloc(c + 1, sizeof(char *));
	c = 0;
	while (rtn[++i])
	{
		if ((rtn[i][0] == '|' && rtn[i][1] && rtn[i][1] != '|')
			|| (rtn[i][0] == '>' && rtn[i][1] == '>' && rtn[i][2])
			|| (rtn[i][0] == '>' && rtn[i][1] != '>' && rtn[i][1])
			|| (rtn[i][0] == '<' && rtn[i][1] == '<' && rtn[i][2])
			|| (rtn[i][0] == '<' && rtn[i][1] != '<' && rtn[i][1]))
		{
			temp = temp_maker(rtn[i]);
			fin[c++] = ft_strdup(temp[0]);
			fin[c++] = ft_strdup(temp[1]);
			ft_doublefree(temp);
		}
		else
			fin[c++] = ft_strdup(rtn[i]);
	}
	return (ft_doublefree(rtn), fin);
}

char	**lex_core(char *str)
{
	char	**rtn;

	str = lex_first_spc_rm(str);
	if (parser_quote_error_chk(str))
		exit (0);
	rtn = ft_calloc((lex_memory_splitter(str)) + 1, sizeof(char *));
	rtn = lex_splitter(str, rtn);
	rtn = pipe_redir_replacer(rtn);
	replace_for_keywords(rtn);
	return (rtn);
}
