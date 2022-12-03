/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:26:48 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 17:21:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
#include "minishell.h"
#include "libft.h"
#include <stdio.h>

static void	initializer(t_values *values, char *arg)
{
	if (arg[0] == '*')
		values->start = 1;
	else
		values->start = 0;
	if (arg[ft_strlen(arg) - 1] == '*')
		values->end = 1;
	else
		values->end = 0;
}

static void	start_parser(t_values *values)
{
	values->i = -1;
	if (!values->start)
		values->i = 0;
	if (values->start)
		while (values->file[++values->i])
			if (ft_strnstr(&values->file[values->i],
					values->split_arg[0], ft_strlen(values->split_arg[0]))
				&& ft_strncmp(values->file,
					values->split_arg[0], ft_strlen(values->split_arg[0])))
					values->matches++;
}

static void	iterator_parser(t_values *values)
{
	while (values->file[values->i] && values->split_arg[values->matches])
	{
		if (ft_strnstr(&values->file[values->i],
				values->split_arg[0], ft_strlen(values->split_arg[0])))
			values->matches++;
		if (values->matches == ft_doublestrlen(values->split_arg))
			break ;
		values->i++;
	}
}

static void	end_parser(t_values *values)
{
	if (values->end)
		if (reverse_search(values->file,
				values->split_arg[ft_doublestrlen(values->split_arg) - 1])
			&& reverse_search(values->file,
				values->split_arg[ft_doublestrlen(values->split_arg) - 1])[1])
			values->end = 2;
	values->end = 0;
}

char	*wildcard_parser(char *file, char *arg)
{
	t_values	values;

	values.matches = 0;
	values.file = file;
	values.split_arg = ft_split(arg, '*');
	initializer(&values, arg);
	if (!values.split_arg || !values.split_arg[0])
		return (ft_doublefree(values.split_arg), NULL);
	start_parser(&values);
	iterator_parser(&values);
	end_parser(&values);
	if (values.matches == ft_doublestrlen(values.split_arg)
		&& (values.end == 2 || values.end == 0))
		return (ft_doublefree(values.split_arg), file);
	return (ft_doublefree(values.split_arg), NULL);
}
