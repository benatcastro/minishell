/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:50:17 by umartin-          #+#    #+#             */
/*   Updated: 2021/10/25 12:54:11 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		while (n--)
		{
			if (*(unsigned char *)s1 != *(unsigned char *)s2)
				return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
			s1++;
			s2++;
		}
	}
	return (0);
}
