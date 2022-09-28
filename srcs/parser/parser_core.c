/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/27 20:52:46 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

char	**parser_core(char **str)
{
	int		i;
	char	*aux;

	i = -1;
	while (++i != ft_doublestrlen(str))
	{
		printf("ANTES\n%s\n", str[i]);
		aux = parser_quotes(str[i]);
		printf("DESPUES\n%s\n", aux);
	}
	return (str);
}

char	*parser_quotes(char *str)
{
	int		a;
	int		c;
	int		b;
	// int		n;
	char	*rtn;

	a = 0;
	c = 0;
	rtn = NULL;
	
	// rtn = malloc(sizeof(char *) * ft_strlen(str) - 2);
	// printf("%s\n", str);
	// while (str[a])
	// {
	// 	if (str[a] == 39)
	// 	{
	// 		while (str[++a] != 39)
	// 			rtn[a] = rtn[c++];
	// 		if ((size_t)a != ft_strlen(str))
	// 			a++;
	// 		else
	// 			break ;
	// 	}
	// 	rtn[a] = rtn[c++];
	// 	a++;
	// }
	// b = 0;
	b = parser_quote_memory(str);
	printf ("%i\n", b);
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
			i++;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			if (checker == 1)
			{
				while ((str[i] != 39) && ((size_t)i != ft_strlen(str)))
				{
					i++;
					if (str[i] == 39)
					{
						b = 0;
						n++;
					}
				}
			}
			else
			{
				while ((str[i] != 34) && ((size_t)i != ft_strlen(str)))
				{
					i++;
					if (str[i] == 34)
					{
						b = 0;
						n++;
					}
				}
			}
		}
		i++;
	}
	return (n);
}
