/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:38:48 by becastro          #+#    #+#             */
/*   Updated: 2022/09/29 16:39:34 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

char	**parser_core(char **str)
{
	int		i;
	char	*aux;

	i = -1;
	while (++i != ft_doublestrlen(str))
	{
		aux = parser_quotes(str[i]);
		printf("DESPUES\n[%s]\n", aux);
		aux = parser_quotes(str[i]);
		if (parser_quote_error_chk(str[i]))
			break ;
		aux = parser_quotes(str[i]);
	}
	return (str);
}

int	parser_quote_error_chk(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] == 39)
		{
			b = 1;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			parser_quote_error_chk_utl_sq(str, &b, &i);
		}
		else if (str[i] == 34)
		{
			b = 1;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			parser_quote_error_chk_utl_dq(str, &b, &i);
		}
		i++;
	}
	return (b);
}

char	*parser_quotes(char *str)
{
	int		i;
	int		n;
	char	**temp;

	temp = malloc(sizeof(char *) * (parser_arg_num(str) + 1));
	i = -1;
	n = 0;
	while (++i <= ((int)ft_strlen(str) - 1))
	{
		if (str[i] == DOUBLE_QUOTE)
			parser_double_q(str, temp, &i, &n);
		else if (str[i] == SINGLE_QUOTE)
			parser_single_q(str, temp, &i, &n);
		else
			parser_no_q(str, temp, &i, &n);
	}
	return (str);
}

int	parser_arg_num(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
			parser_arg_num_ut(str, &i, &n);
		i++;
	}
	return (n);
}
