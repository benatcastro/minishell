/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:33:01 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/01 16:21:01 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"

char	**lex_core(char *str)
{
	int		i;
	char	**rtn;

	i = -1;
	str = lex_first_spc_rm(str);
	if (parser_quote_error_chk(str))
		exit (0);
	rtn = malloc(sizeof(char *) * (lex_memory_splitter(str)) + 1);
	lex_splitter(str, rtn);
	return (rtn);
}

char	*lex_first_spc_rm(char *str)
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

int	lex_memory_splitter(char *str)
{
	int		e;
	int		c;
	char	q;

	e = -1;
	c = 1;
	while (str[++e])
	{
		if (str[e] == 32)
		{
			c++;
			while (str[e] == 32)
				e++;
		}
		if ((str[e] == SINGLE_QUOTE) || (str[e] == DOUBLE_QUOTE))
		{
			q = str[e];
			e++;
			while (str[e] != q)
				e++;
		}
	}
	return (c);
}

char	**lex_splitter(char *str, char **temp)
{
	int		e;
	int		a;
	int		l;
	int		n;
	char	q;
	char	*aux;

	n = 0;
	e = -1;
	a = 0;
	while (str[++e])
	{
		if (str[e] == 32)
		{
			l = 0;
			aux = ft_calloc(sizeof(char *), (e - a) + 1);
			while (a < e)
				aux[l++] = str[a++];
			aux[l] = 0;
			temp[n] = ft_strdup(aux);
			free(aux);
			n++;
			while (str[e] == 32)
				e++;
			a = e;
		}
		if ((str[e] == SINGLE_QUOTE) || (str[e] == DOUBLE_QUOTE))
		{
			q = str[e];
			e++;
			while (str[e] != q)
				e++;
		}
	}
	if (e > a)
	{
		l = 0;
		aux = ft_calloc(sizeof(char *), (e - a) + 1);
		while (a < e)
			aux[l++] = str[a++];
		aux[l] = 0;
		temp[n] = ft_strdup(aux);
		free(aux);
		n++;
	}
	temp[n] = NULL;
	return (temp);
}
