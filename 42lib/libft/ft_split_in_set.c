/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_in_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:02:42 by bena              #+#    #+#             */
/*   Updated: 2022/09/24 14:16:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @brief calculates the size of the double string for allocation.
 *
 * @param s the string to be splitted.
 * @param c the splitting character.
 * @return int the number of strings needed on the double string result
 * (not counting the NULL string).
 */
static int	ft_doublesize(const char *s, char *set)
{
	int		size;

	size = 0;
	while (*s)
	{
		if ((ft_chr_in_set(s[1], set) || !s[1]) && !ft_chr_in_set(*s, set))
			size++;
		s++;
	}
	return (size);
}


/**
 * @brief takes the string pointed by s and creates a double
 * array splitted by the character c (wich is eliminated).
 *
 * @param s the string to split.
 * @param c the splitting character.
 * @return char** the resultant allocation of the splitted
 * string pointed by s.
 */
static char	**get_split_set_char(char const *s, char *c)
{
	char	**result;
	size_t	i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_doublesize(s, c) + 1));
	if (!result)
		return (NULL);
	start = -1;
	i = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (!ft_chr_in_set(s[i], c) && start < 0)
			start = i;
		else if (start >= 0 && (ft_chr_in_set(s[i], c) | i == ft_strlen(s)))
		{
			result[j++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
	result[j] = NULL;
	return (result);
}

/**
 * @brief
 * Iterates the double str from "get_split_set_char" and trims all
 * the remainings chars from set
 * @param s
 * @param set
 * @return char**
 */
char	**ft_split_set(char *s, char *set)
{
	char	**split;
	char	*tmp;
	int		i;

	split = get_split_set_char(s, set);
	i = -1;
	while (split[++i])
	{
		tmp = ft_strtrim(split[i], set);
		free(split[i]);
		split[i] = tmp;
		//free(tmp);
	}
	return (split);
		//replace for ft_replace Str
}



int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	for (size_t i = 0; i < 5; i++)
		printf("(%s\n)", ft_split_set("	    ls	hola    	", "\20\t")[i]);
}
