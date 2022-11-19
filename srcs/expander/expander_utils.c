/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:19:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/19 20:23:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	**expander(char	*str)
{
	int		i;
	char	**temp;
	char	*aux;

	temp = ft_calloc((expand_arg_num(str)) + 1, sizeof(char *));
	temp = expand_splitter(str, temp);
	i = -1;
	i = -1;
	while (temp[++i])
	{
		if ((temp[i][0] == 36) && (ft_strlen(temp[i]) > 1))
		{
			aux = env_finder(temp[i]);
			temp[i] = ft_strdup(aux);
			//free (aux);
		}
	}
	return (temp);
}

void	expand_arg_num_ut2(char *str, int *e, int *c)
{
	(*c)++;
	(*e)++;
	while ((str[(*e)]) && ((str[(*e)] != SINGLE_QUOTE)))
		(*e)++;
	(*e)++;
}

int	expand_arg_num(char *str)
{
	int		e;
	int		c;

	e = -1;
	c = 0;
	while (str[++e])
	{
		if (str[e] && str[e] == SINGLE_QUOTE)
			expand_arg_num_ut2(str, &e, &c);
		else if (str[e] && str[e] == '$')
			expand_arg_num_ut(str, &e, &c);
		else
		{
			c++;
			while ((str[e]) && ((str[e] != '$')) && ((str[e] != SINGLE_QUOTE)))
				e++;
			e--;
		}
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
	while ((str[(*e)]) && ((str[(*e)] != '$') && (str[(*e)] != 32)
			&& (str[(*e)] != SINGLE_QUOTE)))
		(*e)++;
	(*e)--;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	free(s1);
	free(s2);
	return (str);
}
