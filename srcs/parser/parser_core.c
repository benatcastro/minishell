/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/28 17:28:50 by umartin-         ###   ########.fr       */
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
		printf("ANTES\n%s\n", str[i]);
		aux = parser_quotes(str[i]);
		printf("DESPUES\n[%s]\n", aux);
	}
	return (str);
}

char	*parser_quotes(char *str)
{
	int		i;
	int		c;
	//int		a;
	int		checker;
	char	*rtn;
	//char	*exp;

	i = -1;
	c = 0;
	rtn = ft_calloc(sizeof(char *),
			(ft_strlen(str) - parser_quote_memory(str)) + 1);
	if (!rtn)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			if (str[i] == 39)
				checker = 1;
			else
				checker = 2;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			i++;
			if (checker == 1)
			{
				while ((size_t)i != ft_strlen(str))
				{
					if (str[i] == 39)
						break ;
					rtn[c++] = str[i++];
				}
				continue ;
			}
		}
		else
			rtn[c++] = str[i];
	}
	rtn[c] = 0;
	return (rtn);
}

int	parser_expand_memory(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			i++;
			while ((size_t)i != ft_strlen(str))
			{
				if (str[i] == 34)
					break ;
				i++;
				n++;
			}
		}
		i++;
	}
	return (n);
}

int	parser_quote_memory(char *str)
{
	int	n;
	int	i;
	int	b;
	int	checker;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			if (str[i] == 39)
				checker = 1;
			else
				checker = 2;
			b = 1;
			n++;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			i++;
			if (checker == 1)
			{
				while ((size_t)i != ft_strlen(str))
				{
					if (str[i] == 39)
					{
						b = 0;
						n++;
						break ;
					}
					i++;
				}
			}
			else
			{
				while ((size_t)i != ft_strlen(str))
				{
					if (str[i] == 34)
					{
						b = 0;
						n++;
						break ;
					}
					i++;
				}
			}
		}
		i++;
	}
	if (b == 1)
		return (-1);
	return (n);
}
