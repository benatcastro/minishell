/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/10/03 00:22:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

bool	ft_is_quote(unsigned char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		return (true);
	return (false);
}

void	quote_logic(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		while (ft_is_quoted(str, i) && str[i])
		{
			while (ft_is_quote(str[i]))
				i++;
			if (ft_isblank(str[i]))
				str[i] = REPLACE_CHAR;
			i++;
			if (ft_is_quote(str[i]))
				break ;
		}
		while (ft_is_quote(str[i]) && str[i])
			i++;
		while (ft_isblank(str[i]) && str[i])
			i++;
	}
}

bool	ft_is_quoted(const char *ref, unsigned int index)
{
	bool	opens;
	bool	closes;
	int		i;

	opens = false;
	closes = false;
	i = index;
	while (i > 0 && ref[--i])
		if (ft_is_quote(ref[i]))
				opens = true;
	if (ft_is_quote(ref[i]))
		opens = true;
	while (ref[index++])
		if (ft_is_quote(ref[index]))
			closes = true;
	if (opens && closes)
		return (true);
	else
		return (false);
}

void	replace_for_spaces(char **str)
{
	int	y;
	int	x;

	y = -1;
	while (str[++y])
	{
		x = -1;
		while (str[y][++x])
			if (str[y][x] == REPLACE_CHAR)
				str[y][x] = ' ';
	}
}
