/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:37:30 by aalvarez          #+#    #+#             */
/*   Updated: 2022/10/07 19:25:52 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief allocates a copy of the string pointed by s1 and returns it.
 * 
 * @param s1 the string to be copied.
 * @return char* the allocated copy.
 */
char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}
