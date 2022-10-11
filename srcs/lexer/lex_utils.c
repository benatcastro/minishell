/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/10/11 19:33:07 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

void	print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("(%s)\n", str[i]);
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
