/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:25:53 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/23 19:00:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief fills n bytes of the s string with NULL bytes.
 * 
 * @param s string to be filled.
 * @param n number of bytes to fill.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	if (s)
	{
		while (++i < n)
			((unsigned char *)s)[i] = 0;
	}
}
