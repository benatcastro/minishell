/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:03:13 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/23 19:00:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief set len bytes of the b string with the
 * c character (casted to uchar).
 * 
 * @param b string to be setted.
 * @param c character to write on len bytes of the string.
 * @param len number of bytes to set.
 * @return void* string already setted.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = -1;
	if (b)
	{
		while (++i < len)
			((unsigned char *)b)[i] = (unsigned char)c;
	}
	return (b);
}
