/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:58:47 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/30 12:24:17 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

void	parser_double_q(char *str, char **temp, int *i, int *n)
{
	int		u;
	int		c;
	char	*aux;

	u = *i;
	c = 0;
	(*i)++;
	while ((str[*i]) != DOUBLE_QUOTE)
		(*i)++;
	aux = ft_calloc(sizeof(char *),
			((*i - u)) + 2);
	while (u <= *i)
		aux[c++] = str[u++];
	aux[c] = 0;
	temp[*n] = ft_strdup(aux);
	(*n)++;
}

void	parser_single_q(char *str, char **temp, int *i, int *n)
{
	int		u;
	int		c;
	char	*aux;

	u = *i;
	c = 0;
	(*i)++;
	while ((str[*i]) != SINGLE_QUOTE)
		(*i)++;
	aux = ft_calloc(sizeof(char *),
			((*i - u)) + 2);
	while (u <= *i)
		aux[c++] = str[u++];
	aux[c] = 0;
	temp[*n] = ft_strdup(aux);
	(*n)++;
}

void	parser_no_q(char *str, char **temp, int *i, int *n)
{
	int		u;
	int		c;
	char	*aux;

	u = *i;
	(*i)++;
	c = 0;
	while (str[*i])
	{
		if ((str[*i] == DOUBLE_QUOTE) || (str[*i] == SINGLE_QUOTE))
		{
			(*i)--;
			break ;
		}
		(*i)++;
	}
	aux = ft_calloc(sizeof(char *),
			((*i - u)) + 2);
	while (u <= *i)
		aux[c++] = str[u++];
	aux[c] = 0;
	temp[*n] = NULL;
	temp[*n] = ft_str_replace(temp[*n], aux);
	(*n)++;
}

void	parser_arg_num_ut(char *str, int *i, int *n)
{
	int	checker;

	if (str[*i] == 39)
		checker = 1;
	else
		checker = 2;
	(*n)++;
	if (*i + 1 == (int)ft_strlen(str))
		return ;
	(*i)++;
	if (checker == 1)
	{
		while ((*i)++ != (int)ft_strlen(str))
			if (str[*i] == 39)
				break ;
	}
	else if (checker == 2)
		while ((*i)++ != (int)ft_strlen(str))
			if (str[*i] == 34)
				break ;
}
