/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/09/27 14:49:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

/**
 * @brief
 * checks if there are any quotes and if they are closed correctly
 * todo ====first iteration===
 * @param str
 * @return int
 */
bool ft_is_quoted(char *s, u_int32_t index)
{
	int		i;
	int		j;
	bool	closed;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 39)
		{
			// printf("start quote\n");
			j = i;
			closed = false;
		}
		if (str[i] == 39 && closed == false)
		{
			closed = true;
			// printf("end quote\n");
			return (j);
		}
	}
	return (0);
}

char	*replace_quoted_strings(char *str)
{
	int	i;

	i = check_quotes(str);
	if (!i)
		return (NULL);
	printf("TEST (%d)\n", i);
	while (str[++i])
		if (ft_isblank(str[i]))
			str[i] = REPLACE_CHAR;
	return (str);
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
