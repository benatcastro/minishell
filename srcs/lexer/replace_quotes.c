/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:56:34 by becastro          #+#    #+#             */
/*   Updated: 2022/09/26 21:14:06 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

int	check_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((ft_isblank(str[i]) && i > 0) && ft_chr_in_set(str[i - 1], "'"))
		{
			printf("start quote\n");
			while (str[i] != 39 && str[i])
				i++;
		}
		if (str[i] == 39)
		{
			printf("end quote\n");
			return (1);
		}
	}
	return (0);
}
