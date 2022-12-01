/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:58:20 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/01 02:18:34 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

void	lex_quote_ut(char *str, int *i)
{
	int	c;

	c = 0;
	(*i)++;
	while (str[(*i)])
	{
		if (str[(*i)] == 40)
			c++;
		if (str[(*i)] == 41)
		{
			if (c == 0)
				break ;
			else
				c--;
		}
		(*i)++;
	}
}

void	lex_glob_ut(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] != 41)
		(*i)++;
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
