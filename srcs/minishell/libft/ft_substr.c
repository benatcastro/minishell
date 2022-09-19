/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:33:49 by umartin-          #+#    #+#             */
/*   Updated: 2021/10/29 18:15:47 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	result = malloc(sizeof(*s) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (len > 0)
	{
		result[i] = s[start];
		i++;
		len--;
		start++;
	}
	result[i] = '\0';
	return (result);
}
