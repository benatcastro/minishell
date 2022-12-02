/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:19:25 by bena              #+#    #+#             */
/*   Updated: 2022/11/24 16:46:40 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief
 * Takes a string as a paramter and appends the char c to the end of it
 * @param str
 * @param c
 * @return char*
 */
char	*ft_append_char(char *str, char c)
{
	char	*tmp;
	size_t	str_len;

	if (!str)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	str_len = ft_strlen(str) + 1;
	tmp = ft_strdup(str);
	free(str);
	str = ft_calloc(str_len + 1, sizeof(char));
	ft_strlcpy(str, tmp, str_len);
	free(tmp);
	str[str_len - 1] = c;
	return (str);
}
