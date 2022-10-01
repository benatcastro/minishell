/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/10/01 16:15:39 by bena             ###   ########.fr       */
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
	{
		while (ft_is_quoted(str, i) && str[i])
		{
			if (ft_isblank(str[i]))
				str[i] = REPLACE_CHAR;
			i++;
		}
		//printf("(%c)\n", str[i]);
		//printf("SUB WHILE ENDS\n");
		while ((str[i] != SINGLE_QUOTE || str[i] != DOUBLE_QUOTE) && str[i])
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
