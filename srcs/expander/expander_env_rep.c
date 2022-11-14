/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_rep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:29:59 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/14 15:36:14 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	*env_finder(char *str)
{
	int		i;
	int		n;
	char	*val;
	char	*p;

	i = -1;
	str = expand_first_trimmer(str);
	p = ft_itoa((int)getpid());
	if (str[0] == 36)
		return (p);
	while (g_data.env[++i])
	{
		if ((!ft_strncmp(str, g_data.env[i], (num_until_equal(g_data.env[i]))))
			&& ((int)ft_strlen(str) == num_until_equal(g_data.env[i])))
		{
			val = ft_calloc(sizeof(char *),
					(ft_strlen(g_data.env[i]) - ft_strlen(str)));
			n = (ft_strlen(str));
			val = env_val_maker(val, &n, &i);
			free (str);
			return (val);
		}
	}
	return (val = "", free (str), val);
}

char	*env_val_maker(char *val, int *n, int *i)
{
	int	r;

	r = 0;
	while (g_data.env[*i][++(*n)])
		val[r++] = g_data.env[*i][*n];
	val[r] = 0;
	return (val);
}

int	num_until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 61)
			return (i);
		i++;
	}
	return (0);
}
