/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/01 16:24:51 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"

char	**parser_core(char **str, char **env)
{
	int		i;
	int		a;
	char	**aux;
	char	*rtn;

	i = -1;
	aux = NULL;
	while (++i != ft_doublestrlen(str))
	{
		aux = parser_quotes(str[i]);
		a = -1;
		while (aux[++a])
			printf("%s\n", aux[a]);
		printf("\n");
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

char	**parser_quotes(char *str)
{
	int		i;
	int		n;
	char	**temp;

	temp = malloc(sizeof(char *) * (parser_arg_num(str)) + 1);
	temp[(parser_arg_num(str))] = NULL;
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
	return (temp);
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
		else
		{
			n++;
			while (i++ != (int)ft_strlen(str))
				if ((str[i + 1] == 39) || (str[i + 1] == 34))
					break ;
		}
		i++;
	}
	return (n);
}
