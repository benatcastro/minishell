/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:00:07 by becastro          #+#    #+#             */
/*   Updated: 2022/09/20 17:04:14 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief finds the last occurence of the char c in the
 * string pointed by s.
 *
 * @param s the string to search.
 * @param c the character to search.
 * @return char* reference to the first match (or NULL if c
 * was not fund on the string).
 */
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
