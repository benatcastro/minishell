/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_splitter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:16:53 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/21 17:28:54 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

void	expand_splitter_ut_ut(char *str, char *aux, int e[3], char **rtn)
{
	e[0]++;
	while ((str[e[0]]) && ((str[e[0]] != SINGLE_QUOTE)))
		e[0]++;
	rtn[e[1]] = expand_splitter_ut2(str, aux, &e[0], &e[2]);
}

void	expand_splitter_ut_ut2(char *str, char *aux, int e[3], char **rtn)
{
	while ((str[e[0]]) && ((str[e[0]] != '$')))
		e[0]++;
	e[0]--;
	rtn[e[1]] = expand_splitter_ut2(str, aux, &e[0], &e[2]);
}

char	**expand_splitter(char *str, char **rtn)
{
	int		e[3];
	char	*aux;

	aux = NULL;
	e[0] = -1;
	e[1] = 0;
	while (str[++e[0]])
	{
		e[2] = e[0];
		if (str[e[0]] && str[e[0]] == SINGLE_QUOTE)
			expand_splitter_ut_ut(str, aux, e, rtn);
		else if (str[e[0]] == '$')
		{
			expand_splitter_ut(str, &e[0]);
			rtn[e[1]] = expand_splitter_ut2(str, aux, &e[0], &e[2]);
		}
		else
			expand_splitter_ut_ut2(str, aux, e, rtn);
		e[1]++;
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
