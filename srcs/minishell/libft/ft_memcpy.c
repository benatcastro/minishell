/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:49:31 by umartin-          #+#    #+#             */
/*   Updated: 2021/10/22 11:19:44 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	const char		*aux;
	size_t			c;

	c = 0;
	temp = dst;
	aux = src;
	if (temp == NULL && aux == NULL)
		return (dst);
	while (n > 0)
	{
		temp[c] = aux[c];
		n--;
		c++;
	}
	return (dst);
}
