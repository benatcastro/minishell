/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:10:18 by umartin-          #+#    #+#             */
/*   Updated: 2022/02/08 17:52:31 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_gnl(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *final, char *rd)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!final)
	{
		final = (char *)malloc(1 * sizeof(char));
		final[0] = '\0';
	}
	if (!final || !rd)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen_gnl(final)
					+ ft_strlen_gnl(rd)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (final)
		while (final[++i] != '\0')
			result[i] = final[i];
	while (rd[j] != '\0')
		result[i++] = rd[j++];
	result[i] = '\0';
	free (final);
	return (result);
}
