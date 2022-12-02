/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:26:48 by becastro          #+#    #+#             */
/*   Updated: 2022/11/25 11:14:34 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
#include "libft.h"
#include <stdio.h>

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
int	wildcard_parser(char *file, char *arg)
{
	char	**split_arg;
	int		start;
	int		end;
	int		i;
	int		matches;
	char	*temp;

	matches = 0;
	temp = ft_strdup(file);
	initializer(&start, &end, arg);
	split_arg = ft_split(arg, '*');
	if (!split_arg || !split_arg[0])
		return (ft_doublefree(split_arg), 1);
	ft_doubleprint(split_arg);
	i = -1;
	if (start)
		while (file[++i])
			if (ft_strnstr(&file[i], split_arg[0], ft_strlen(split_arg[0])))
				matches++;
	while (file[i] && split_arg[matches])
	{
		if (ft_strnstr(&file[i], split_arg[0], ft_strlen(split_arg[0])))
			matches++;
		if (matches == ft_doublestrlen(split_arg))
			break ;
	}
	if (end)
	{
		if (ft_strnstr(file, split_arg[ft_doublestrlen(split_arg) - 1],
				ft_strlen(split_arg[ft_doublestrlen(split_arg) - 1])))
		{
			matches++;
			end = 2;
		}
	}
			// if (ft_strchr(file, '*')[1] != 0)
			// 	end = 2;
	fprintf(stderr, "file after parse: %s end: %d\n", temp, end);
	if (matches == ft_doublestrlen(split_arg) && (end == 2 || end == 0))
		return ((void)printf("Valid file\n"), 1);
	return (0);
}
