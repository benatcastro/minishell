/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:36:23 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/23 19:00:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/lexer.h"

void	parser_quote_error_chk_utl_sq(char *str, int *b, int *i)
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

void	parser_quote_error_chk_utl_dq(char *str, int *b, int *i)
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
