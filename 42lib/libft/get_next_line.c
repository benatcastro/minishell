/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:35:40 by umartin-          #+#    #+#             */
/*   Updated: 2022/04/12 12:25:23 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_final_rtn_gnl(char *final)
{
	char	*str;
	int		i;

	i = 0;
	if (!final[i])
		return (NULL);
	while (final[i] && final[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (final[i] && final[i] != '\n')
	{
		str[i] = final[i];
		i++;
	}
	if (final[i] == '\n')
	{
		str[i] = final[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean_final(char *final)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	while (final[i] && final[i] != '\n')
		i++;
	if (!final[i])
	{
		free (final);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(final) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (final[i])
		str[c++] = final[i++];
	str[c] = '\0';
	free (final);
	return (str);
}

char	*ft_read_static_gnl(int fd, char *final)
{
	char	*rd;
	int		i;

	rd = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!rd)
		return (NULL);
	i = 1;
	while (!ft_strchr_gnl(final, '\n') && i != 0)
	{
		i = read(fd, rd, BUFFER_SIZE);
		if (i == -1)
		{
			free(rd);
			return (NULL);
		}
		rd[i] = '\0';
		final = ft_strjoin_gnl(final, rd);
	}
	free (rd);
	return (final);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	final = ft_read_static_gnl(fd, final);
	if (!final)
		return (NULL);
	rtn = ft_final_rtn_gnl(final);
	final = ft_clean_final(final);
	return (rtn);
}
