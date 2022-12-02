/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:22:28 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 16:48:24 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief
 * Str compare refactorized
 * @param s1
 * @param s2
 * @return true
 * @return false
 */
int	ft_strcmp(char *s1, char *s2)
{
	int32_t	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
