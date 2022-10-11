/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:19:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/11 17:51:26 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	**expander(char	*str, char **env)
{
	int		i;
	int		n;
	int		a;
	char	**temp;
	char	*aux;

	temp = malloc(sizeof(char *) * (expand_arg_num(str)) + 1);
	temp = expand_splitter(str, temp);
	i = -1;
	i = -1;
	n = 0;
	while (temp[++i])
	{
		if ((temp[i][0] == 36) && (ft_strlen(temp[i]) > 1))
		{
			aux = env_replacer(temp[i], env);
			temp[i] = ft_strdup(aux);
		}
	}
	return (temp);
}

int	expand_arg_num(char *str)
{
	int		e;
	int		c;

	e = 0;
	c = 0;
	while (str[e])
	{
		if (str[e] == 36)
			expand_arg_num_ut(str, &e, &c);
		else
		{
			c++;
			while ((str[e]) && ((str[e] != '$')))
				e++;
		}
		e++;
	}
	return (c);
}

void	expand_arg_num_ut(char *str, int *e, int *c)
{
	if (str[(*e) + 1] == 36)
	{
		(*c)++;
		(*e)++;
		return ;
	}
	(*c)++;
	(*e)++;
	while ((str[(*e)]) && ((str[(*e)] != '$') && (str[(*e)] != 32)))
		(*e)++;
	(*e)--;
}
