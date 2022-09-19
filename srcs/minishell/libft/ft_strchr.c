/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:50:51 by umartin-          #+#    #+#             */
/*   Updated: 2021/10/22 13:55:22 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (*str == (unsigned char)c)
		return ((char *)str);
	while (*str++)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
	}
	return (NULL);
}
