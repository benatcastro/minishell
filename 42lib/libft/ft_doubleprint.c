/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:28:02 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/16 18:40:18 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_doubleprint(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		printf("Error\n");
		return ;
	}
	while (str[i])
	{
		printf("str[%d] == %s\n", i, str[i]);
		i++;
	}
}
