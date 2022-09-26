/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/09/26 21:45:03 by becastro         ###   ########.fr       */
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
int	check_quotes(char *str)
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
			str[i] = 1;
	return (str);
}
