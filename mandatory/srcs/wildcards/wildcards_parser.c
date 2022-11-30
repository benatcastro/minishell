/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:26:48 by becastro          #+#    #+#             */
/*   Updated: 2022/11/30 10:47:56 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
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

/**
 * @brief
 * Takes a file from the directory and checks if it's compatible with wildcard
 * arg, if the arg is * always returns 1
 * @param file -> string to be checked
 * @param arg -> arg containing wildcard
 * @return 1 if compatible 0 if not
 */
void	wildcard_parser(char *file, char *arg, char **final_args)
{
	char	**split_arg;
	int		start;
	int		end;
	int		i;
	int		matches;

	matches = 0;
	initializer(&start, &end, arg);
	split_arg = ft_split(arg, '*');
	if (!split_arg || !split_arg[0])
		return ((void)ft_doublefree(split_arg));
	// fprintf(stderr, "FILE: %s\nSPLITTED ARG:\n", file);
	// ft_doubleprint(split_arg);
	// fprintf(stderr, "\n");
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
	{
		if (reverse_search(file, split_arg[ft_doublestrlen(split_arg) - 1])
			&& reverse_search(file, split_arg[ft_doublestrlen(split_arg) - 1])[1])
			end = 2;
		// fprintf(stderr, "Reverse search tests: %s\n", reverse_search(file, split_arg[ft_doublestrlen(split_arg) - 1]));
	}
	// fprintf(stderr, "end: %d matches : %d need %d\n===========================================================\n", end, matches, ft_doublestrlen(split_arg));
	if (matches == ft_doublestrlen(split_arg) && (end == 2 || end == 0))
		add_s
		// return ((void)printf("Valid file\n===========================================================\n"), 1);
	return (0);
}
