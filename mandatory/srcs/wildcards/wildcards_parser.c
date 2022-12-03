/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:26:48 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 02:19:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
#include "minishell.h"
#include "libft.h"
#include <stdio.h>

static char	*reverse_search(const char *haystack, const char *needle)
{
	int	i;

	i = ft_strlen(haystack);
	while (i >= 0)
	{
		if (haystack[i] == needle[0]
			&& ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char *)&haystack[i]);
		i--;
	}
	return (NULL);
}

static void	initializer(int *start, int *end, char *arg)
{
	if (arg[0] == '*')
		*start = 1;
	else
		*start = 0;
	if (arg[ft_strlen(arg) - 1] == '*')
		*end = 1;
	else
		*end = 0;
}

static int	start_parser(int *start, int *matches, char *file, char **split_arg)
{
	int	i;

	i = -1;
	if ((!start))
		i = 0;
	if (*(start))
		while (file[++i])
			if (ft_strnstr(&file[i], split_arg[0], ft_strlen(split_arg[0]))
				&& ft_strncmp(file, split_arg[0], ft_strlen(split_arg[0])))
				*matches++;
	return (i);
}
/**
 * @brief
 * Takes a file from the directory and checks if it's compatible with wildcard
 * arg, if the arg is * always returns 1
 * @param file -> string to be checked
 * @param arg -> arg containing wildcard
 * @return 1 if compatible 0 if not
 */
char	*wildcard_parser(char *file, char *arg)
{
	char	**split_arg;
	int		start;
	int		end;
	int		i;
	int		matches;

	matches = 0;
	split_arg = ft_split(arg, '*');
	initializer(&start, &end, arg);
	if (!split_arg || !split_arg[0])
		return (ft_doublefree(split_arg), NULL);
	i = -1;
	if (!start)
		i = 0;
	if (start)
		while (file[++i])
			if (ft_strnstr(&file[i], split_arg[0], ft_strlen(split_arg[0]))
				&& ft_strncmp(file, split_arg[0], ft_strlen(split_arg[0])))
				matches++;
	while (file[i] && split_arg[matches])
	{
		if (ft_strnstr(&file[i], split_arg[0], ft_strlen(split_arg[0])))
			matches++;
		if (matches == ft_doublestrlen(split_arg))
			break ;
		i++;
	}
	if (end)
		if (reverse_search(file, split_arg[ft_doublestrlen(split_arg) - 1])
			&& reverse_search(file,split_arg[ft_doublestrlen(split_arg) - 1])[1])
			end = 2;
	if (matches == ft_doublestrlen(split_arg) && (end == 2 || end == 0))
		return (ft_doublefree(split_arg), file);
	return (ft_doublefree(split_arg), NULL);
}
