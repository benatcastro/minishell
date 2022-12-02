/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:36:23 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/02 15:30:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

void	parser_q_error_chk_utl_sq(char *str, int *b, int *i)
{
	while ((size_t)(*i)++ != ft_strlen(str))
	{
		if (str[*i] == 39)
		{
			*b = 0;
			break ;
		}
	}
}

void	parser_q_error_chk_utl_dq(char *str, int *b, int *i)
{
	while ((size_t)(*i)++ != ft_strlen(str))
	{
		if (str[*i] == 34)
		{
			*b = 0;
			break ;
		}
	}
}

void	parser_arg_num_ut2(char *str, int *e, int *c)
{
	int	b;

	(*c)++;
	b = 0;
	while (str[++(*e)])
	{
		if (str[(*e)] == 40)
			b++;
		if (str[(*e)] == 41)
		{
			if (b == 0)
				break ;
			else
				b--;
		}
	}
}

void	parser_arg_num_ut(char *str, int *e, char q, int *c)
{
	if ((str[(*e)] == SINGLE_QUOTE) || (str[(*e)] == DOUBLE_QUOTE))
	{
		(*c)++;
		q = str[(*e)++];
		while (str[(*e)] != q)
			(*e)++;
	}
	else if (str[(*e)] == 40)
		parser_arg_num_ut2(str, &(*e), &(*c));
	else
	{
		(*c)++;
		while ((str[(*e)])
			&& (str[(*e)] != SINGLE_QUOTE)
			&& (str[(*e)] != DOUBLE_QUOTE) && (str[(*e)] != 40))
			(*e)++;
		(*e)--;
	}
}

int	parser_arg_num(char *str)
{
	int		e;
	int		c;
	char	q;

	e = -1;
	c = 0;
	q = 0;
	while (str[++e])
		parser_arg_num_ut(str, &e, q, &c);
	return (c);
}
