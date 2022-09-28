/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/09/28 18:33:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

void	quote_logic(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_is_quoted(str, i) && ft_isblank(str[i]))
			str[i] = REPLACE_CHAR;
}

bool	ft_is_quoted(const char *ref, unsigned int index)
{
	bool	opens;
	bool	closes;
	int		i;

	opens = false;
	closes = false;
	i = index;
	if (i > 0)
		while (ref[--i] && i > 0)
			if (ref[i] == SINGLE_QUOTE || ref[i] == DOUBLE_QUOTE)
				opens = true;
	if (ref[i] == SINGLE_QUOTE || ref[i] == DOUBLE_QUOTE)
		opens = true;
	while (ref[index++] && ref[index])
		if (ref[index] == SINGLE_QUOTE || ref[index] == DOUBLE_QUOTE)
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
