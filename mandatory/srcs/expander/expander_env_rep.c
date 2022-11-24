/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env_rep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:29:59 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 20:00:12 by umartin-         ###   ########.fr       */
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
	p = ft_itoa(g_data.ms_pid);
	if (str[0] == 36)
		return (p);
	else if (str[0] == 63)
		return (ft_itoa(g_data.exit_val));
	while (g_data.env[++i])
	{
		if ((!ft_strncmp(str, g_data.env[i], (num_until_equal(g_data.env[i]))))
			&& ((int)ft_strlen(str) == num_until_equal(g_data.env[i])))
		{
			val = ft_calloc(sizeof(char *),
					(ft_strlen(g_data.env[i]) - ft_strlen(str)));
			n = (ft_strlen(str));
			val = env_val_maker(val, &n, &i);
			return (free (str), val);
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

char	*ft_strdup_free(char *s1)
{
	char	*result;
	int		i;

	result = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	free(s1);
	return (result);
}

char	*double_joiner(char **temp)
{
	int		i;
	char	*aux;
	char	*rtn;

	i = 1;
	rtn = ft_strdup(temp[0]);
	while (temp[i])
	{
		aux = ft_strdup(temp[i]);
		rtn = ft_strjoin_free(rtn, aux);
		i++;
	}
	return (rtn);
}
