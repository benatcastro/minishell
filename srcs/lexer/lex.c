/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:58:04 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/19 22:17:11 by umartin-         ###   ########.fr       */
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
		else if (ft_chr_in_set('\\', str[i]))
			str[i] = ft_str_replace(str[i], "ASCII92");
	}
	return (1);
}

// void	temp_utis_pipe

char	**temp_maker(char *rtn)
{
	char	*t1;
	char	*t2;
	char	**temp;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	if (rtn[0] == '|')
	{
		c = 0;
		t1 = ft_calloc(2, sizeof(char));
		t1[0] = '|';
		t1[1] = 0;
		t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
		while (rtn[++c])
			t2[c - 1] = rtn[c];
		t2[c - 1] = 0;
	}
	if (rtn[0] == '<' && rtn[1] != '<')
	{
		c = 0;
		t1 = ft_calloc(2, sizeof(char));
		t1[0] = '<';
		t1[1] = 0;
		t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
		while (rtn[++c])
			t2[c - 1] = rtn[c];
		t2[c - 1] = 0;
	}
	if (rtn[0] == '<' && rtn[1] == '<')
	{
		c = 1;
		t1 = ft_calloc(3, sizeof(char));
		t1[0] = '<';
		t1[1] = '<';
		t1[2] = 0;
		t2 = ft_calloc(ft_strlen(rtn) - 1, sizeof(char));
		while (rtn[++c])
			t2[c - 2] = rtn[c];
		t2[c - 2] = 0;
	}
	if (rtn[0] == '>' && rtn[1] != '>')
	{
		c = 0;
		t1 = ft_calloc(2, sizeof(char));
		t1[0] = '>';
		t1[1] = 0;
		t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
		while (rtn[++c])
			t2[c - 1] = rtn[c];
		t2[c - 1] = 0;
	}
	if (rtn[0] == '>' && rtn[1] == '>')
	{
		c = 1;
		t1 = ft_calloc(3, sizeof(char));
		t1[0] = '>';
		t1[1] = '>';
		t1[2] = 0;
		t2 = ft_calloc(ft_strlen(rtn) - 1, sizeof(char));
		while (rtn[++c])
			t2[c - 2] = rtn[c];
		t2[c - 2] = 0;
	}
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	temp[2] = NULL;
	return (free(t1), free(t2), temp);
}

char	**pipe_redir_replacer(char **rtn)
{
	int		i;
	int		c;
	char	**fin;
	char	**temp;

	i = -1;
	c = 0;
	while (rtn[++i])
	{
		if ((rtn[i][0] == '|' && rtn[i][1])
			|| (rtn[i][0] == '>' && rtn[i][1] == '>' && rtn[i][2])
			|| (rtn[i][0] == '>' && rtn[i][1] != '>' && rtn[i][1])
			|| (rtn[i][0] == '<' && rtn[i][1] == '<' && rtn[i][2])
			|| (rtn[i][0] == '<' && rtn[i][1] != '<' && rtn[i][1]))
			c += 2;
		else
			c++;
	}
	fin = ft_calloc(c + 1,sizeof(char *));
	i = -1;
	c = 0;
	while (rtn[++i])
	{
		if ((rtn[i][0] == '|' && rtn[i][1])
			|| (rtn[i][0] == '>' && rtn[i][1] == '>' && rtn[i][2])
			|| (rtn[i][0] == '>' && rtn[i][1] != '>' && rtn[i][1])
			|| (rtn[i][0] == '<' && rtn[i][1] == '<' && rtn[i][2])
			|| (rtn[i][0] == '<' && rtn[i][1] != '<' && rtn[i][1]))
		{
			temp = temp_maker(rtn[i]);
			fin[c++] = ft_strdup(temp[0]);
			fin[c++] = ft_strdup(temp[1]);
		}
		else
			fin[c++] = ft_strdup(rtn[i]);
	}
	fin[c] = 0;
	return (fin);
}

char	**lex_core(char *str)
{
	char	**rtn;

	str = lex_first_spc_rm(str);
	if (parser_quote_error_chk(str))
		exit (0);
	rtn = ft_calloc((lex_memory_splitter(str)) + 1, sizeof(char *));
	// rtn = malloc(sizeof(char *) * (lex_memory_splitter(str)) + 1);
	rtn = lex_splitter(str, rtn);
	rtn = pipe_redir_replacer(rtn);
	replace_for_keywords(rtn);
	return (rtn);
}
