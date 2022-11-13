/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:19:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 05:26:55 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	**expander(char	*str, char **env)
{
	int		i;
	int		n;
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
			aux = env_finder(temp[i], env);
			temp[i] = ft_strdup(aux);
			//free (aux);
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
