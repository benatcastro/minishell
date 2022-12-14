/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/02 15:30:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"

char	**parser_core(char **str)
{
	int		i;
	char	**aux;
	char	**dub;
	char	*rtn;

	i = -1;
	aux = NULL;
	dub = ft_calloc((ft_doublestrlen(str) + 1), sizeof(char *));
	while (str[++i])
	{
		aux = parser_quotes(str[i]);
		aux = parser_double_quote_free(aux);
		rtn = expander_core(aux);
		dub[i] = ft_strdup(rtn);
		free (rtn);
	}
	ft_doublefree (str);
	return (dub);
}

char	**parser_double_quote_free(char **str)
{
	char	**rtn;
	int		i;
	int		c;
	int		d;

	i = -1;
	c = 0;
	d = -1;
	while (str[++i])
	{
		if (str[i][0] == 34 && str[i][1] == 34)
			c++;
	}
	i = -1;
	rtn = ft_calloc((ft_doublestrlen(str) - c + 1), sizeof(char *));
	while (str[++i])
	{
		if (str[i][0] == 34 && str[i][1] == 34)
			continue ;
		else
			rtn[++d] = ft_strdup(str[i]);
	}
	ft_doublefree(str);
	return (rtn);
}

int	parser_q_error_chk(char *str)
{
	int	i;
	int	b;

	i = -1;
	b = 0;
	while (str[++i])
	{
		if (str[i] == 39)
		{
			if (b == 1)
				b = 0;
			else if (b == 0)
				b = 1;
		}
		else if (str[i] == 34)
		{
			if (b == 2)
				b = 0;
			else if (b == 0)
				b = 2;
		}
	}
	if (b != 0)
		printf ("BASHado: Error: unclosed quotes\n");
	return (b);
}

int	parser_paren_error_chk(char *str)
{
	int	i;
	int	b;

	i = -1;
	b = 0;
	while (str[++i])
	{
		if (str[i] == 40)
			b++;
		else if (str[i] == 41)
		{
			if (b == 0)
				return (printf("BASHado: Error: unclosed parentheses\n"), 1);
			else
				b--;
		}
	}
	if (b != 0)
		printf ("BASHado: Error: unclosed parentheses\n");
	return (b);
}

char	**parser_quotes(char *str)
{
	int		i;
	int		n;
	char	**temp;

	temp = ft_calloc((parser_arg_num(str)) + 1, sizeof(char *));
	temp[(parser_arg_num(str))] = NULL;
	i = -1;
	n = 0;
	while (++i <= ((int)ft_strlen(str) - 1))
	{
		if (str[i] == DOUBLE_QUOTE)
			parser_double_q(str, temp, &i, &n);
		else if (str[i] == SINGLE_QUOTE)
			parser_single_q(str, temp, &i, &n);
		else if (str[i] == 40)
			parser_paren(str, temp, &i, &n);
		else
			parser_no_q(str, temp, &i, &n);
	}
	return (temp);
}
