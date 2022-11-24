/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_splitter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:16:53 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 18:15:44 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	**expand_splitter(char *str, char **rtn)
{
	int		e[2];
	int		l;
	char	*aux;

	e[0] = -1;
	e[1] = 0;
	aux = NULL;
	while (str[++e[0]])
	{
		l = e[0];
		if (str[e[0]] == 36)
		{
			expand_splitter_ut(str, &e[0]);
			rtn[e[1]] = expand_splitter_ut2(str, aux, &e[0], &l);
		}
		else
		{
			while ((str[e[0]]) && ((str[e[0]] != '$')))
				e[0]++;
			e[0]--;
			rtn[e[1]] = expand_splitter_ut2(str, aux, &e[0], &l);
		}
		e[1]++;
	}
	return (free(str), str = NULL, rtn);
}

char	*expand_splitter_ut2(char *str, char *aux, int *e, int *l)
{
	int		a;
	char	*temp;

	aux = ft_calloc(sizeof(char *), ((*e) - (*l)) + 1);
	a = 0;
	while ((*l) <= (*e))
		aux[a++] = str[(*l)++];
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
		while ((str[(*e)]) && ((str[(*e)] != 32))
			&& ((str[(*e)] < 33) || (str[(*e)] > 47))
			&& ((str[(*e)] < 58) || (str[(*e)] > 62))
			&& ((str[(*e)] < 64) || (str[(*e)] > 64)))
			(*e)++;
		(*e)--;
	}
}
