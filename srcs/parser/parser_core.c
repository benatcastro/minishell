/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/29 16:28:25 by becastro         ###   ########.fr       */
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
		expander_core(str);
	}
	return (str);
}

char	*parser_quotes(char *str)
{
	int		i;
	int		c;
	int		checker;
	char	*rtn;

	i = 0;
	c = 0;
	printf ("%i\n", parser_quote_memory(str));
	rtn = ft_calloc(sizeof(char *), (ft_strlen(str) - parser_quote_memory(str)) + 1);
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			if (str[i] == 39)
				checker = 1;
			else
				checker = 2;
			i++;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			if (checker == 1)
			{
				while ((str[i] != 39) && ((size_t)i != ft_strlen(str)))
					rtn[c++] = str[i++];
			}
			else
			{
				while ((str[i] != 34) && ((size_t)i != ft_strlen(str)))
					rtn[c++] = str[i++];
			}
		}
		rtn[c++] = str[i++];
	}
	return (rtn);
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
