/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:11 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

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
	int		i[2];
	int		n;

	n = 0;
	i[0] = -1;
	i[1] = 0;
	while (str[++i[0]])
	{
		if (str[i[0]] == 32)
		{
			lex_splitter_ut(temp, str, i, &n);
			while (str[i[0]] == 32)
				i[0]++;
			i[1] = i[0];
		}
		if ((str[i[0]] == SINGLE_QUOTE) || (str[i[0]] == DOUBLE_QUOTE))
			lex_splitter_quote_ut(str, &i[0]);
	}
	if (i[0] > i[1])
		lex_splitter_ut(temp, str, i, &n);
	free (str);
	return (temp[n] = 0, temp);
}

void	lex_splitter_ut(char **temp, char *str, int i[2], int *n)
{
	char	*aux;
	int		l;

	l = 0;
	aux = ft_calloc(sizeof(char *), ((i[0]) - (i[1])) + 1);
	while ((i[1]) < (i[0]))
		aux[l++] = str[(i[1])++];
	aux[l] = 0;
	temp[(*n)] = ft_strdup(aux);
	free(aux);
	(*n)++;
}

void	lex_splitter_quote_ut(char *str, int *e)
{
	char	q;

	q = str[(*e)];
	(*e)++;
	while (str[(*e)] != q)
		(*e)++;
}

void	replace_for_keywords(char **str)
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
}
