/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_rep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:29:59 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/05 19:42:30 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	*env_replacer(char *str, char **env)
{
	int		i;
	int		n;
	int		r;
	char	*val;
	char	*p;

	i = -1;
	str = expand_first_trimmer(str);
	p = ft_itoa((int)getpid());
	if (str[0] == 36)
		return (p);
	while (env[++i])
	{
		if ((!ft_strncmp(str, env[i], (num_until_equal(env[i]))))
			&& (ft_strlen(str) == num_until_equal(env[i])))
		{
			val = ft_calloc(sizeof(char *),
					(ft_strlen(env[i]) - ft_strlen(str)));
			n = (ft_strlen(str));
			val = env_val_maker(val, env, &n, &i);
			return (val);
		}
	}
	val = "";
	return (val);
}

char	*env_val_maker(char *val, char **env, int *n, int *i)
{
	int	r;

	r = 0;
	while (env[*i][++(*n)])
		val[r++] = env[*i][*n];
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
