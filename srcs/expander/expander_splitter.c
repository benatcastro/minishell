/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_splitter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:16:53 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/17 20:31:23 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	**expand_splitter(char *str, char **rtn)
{
	int		e;
	int		n;
	int		l;
	char	*aux;

	aux = NULL;
	e = -1;
	n = 0;
	while (str[++e])
	{
		l = e;
		if (str[e] && str[e] == SINGLE_QUOTE)
		{
			e++;
			while ((str[e]) && ((str[e] != SINGLE_QUOTE)))
				e++;
			rtn[n] = expand_splitter_ut2(str, aux, &e, &l);
		}
		else if (str[e] == '$')
		{
			expand_splitter_ut(str, &e);
			rtn[n] = expand_splitter_ut2(str, aux, &e, &l);
		}
		else
		{
			while ((str[e]) && ((str[e] != '$')))
				e++;
			e--;
			rtn[n] = expand_splitter_ut2(str, aux, &e, &l);
		}
		n++;
	}
	return (rtn);
}

char	*expand_splitter_ut2(char *str, char *aux, int *e, int *l)
{
	int		a;
	char	*temp;

	aux = ft_calloc(sizeof(char *), ((*e) - (*l)) + 1);
	a = 0;
	while ((*l) <= (*e))
		aux[a++] = str[(*l)++];
	aux[(*l)] = 0;
	temp = ft_strdup(aux);
	free (aux);
	return (temp);
}

void	expand_splitter_ut(char *str, int *e)
{
	if (str[(*e) + 1] == 36)
		(*e)++;
	else
	{
		(*e)++;
		while ((str[(*e)]) && ((str[(*e)] != '$') && (str[(*e)] != 32)
		&& (str[(*e)] != SINGLE_QUOTE)))
			(*e)++;
		(*e)--;
	}
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
