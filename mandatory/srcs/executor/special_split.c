/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:06:33 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 16:55:47 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>

static int	ft_doublesize(const char *s, char c)
{
	int		size;

	size = 0;
	while (*s)
	{
		if ((s[1] == c || !s[1]) && *s != c)
			size++;
		s++;
	}
	return (size);
}

size_t	ft_strlcpy_exec(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = -1;
	if (dstsize != 0)
	{
		while (src[++i] && i < dstsize - 1)
			dst[i] = src[i];
		dst[i] = 47;
		dst[i + 1] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_substr_exec(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	result = ft_calloc((len + 2), sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy_exec(result, s, len + 1);
	return (result);
}

char	**ft_split_exec(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_doublesize(s, c) + 2));
	if (!result)
		return (NULL);
	start = -1;
	i = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s)))
		{
			result[j++] = ft_substr_exec(s, start, (i - start));
			start = -1;
		}
	}
	result[j] = NULL;
	return (result);
}
