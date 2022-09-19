/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:41:42 by umartin-          #+#    #+#             */
/*   Updated: 2021/10/22 14:52:16 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;
	int		len;

	len = ft_strlen(str);
	if (*(str + len) == (char) c)
		return ((char *)str + len);
	temp = NULL;
	while (str)
	{
		if (*str == (unsigned char)c)
			temp = (char *)str;
		if (*str == '\0')
			break ;
		str++;
	}
	return (temp);
}
