/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:54:06 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/24 16:48:22 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief finds the first occurence of the char c in the
 * string pointed by s.
 * 
 * @param s the string to search.
 * @param c the character to search.
 * @return char* reference to the first match (or NULL if c
 * was not fund on the string).
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
