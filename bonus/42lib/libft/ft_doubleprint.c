/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:28:02 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 16:46:59 by umartin-         ###   ########.fr       */
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
