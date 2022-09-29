/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/09/29 16:28:25 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/09/28 17:28:50 by umartin-         ###   ########.fr       */
>>>>>>> simple quote parse
=======
/*   Updated: 2022/09/28 21:35:37 by umartin-         ###   ########.fr       */
>>>>>>> separated quotes
=======
/*   Updated: 2022/09/29 11:19:32 by umartin-         ###   ########.fr       */
>>>>>>> parser v1
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
<<<<<<< HEAD
		aux = parser_quotes(str[i]);
<<<<<<< HEAD
		expander_core(str);
=======
		printf("DESPUES\n[%s]\n", aux);
>>>>>>> simple quote parse
=======
		//printf("ANTES\n%s\n", str[i]);
		aux = parser_quotes(str[i]);
		//printf("DESPUES\n[%s]\n", aux);
>>>>>>> separated quotes
	}
	return (str);
}

int	parser_quote_error_chk(char *str)
{
	int	i;
	int	b;
	int	checker;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			if (str[i] == 39)
				checker = 1;
			else
				checker = 2;
			b = 1;
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
						break ;
					}
					i++;
				}
			}
		}
		i++;
	}
	return (b);
}

char	*parser_quotes(char *str)
{
	int		i;
	int		u;
	int		c;
	int		n;
	char	**temp;
	char	*aux;

	temp = malloc(sizeof(char *) * (parser_arg_num(str) + 1));
	i = -1;
	n = 0;
	c = 0;
	while (++i <= ((int)ft_strlen(str) - 1))
	{
		if (str[i] == DOUBLE_QUOTE)
		{
			u = i;
			i++;
			while (str[i] != DOUBLE_QUOTE)
				i++;
			aux = ft_calloc(sizeof(char *),
					(ft_strlen(str) - (i - u)) + 1);
			while (u <= i)
			{
				aux[c] = str[u];
				u++;
				c++;
			}
			c = 0;
			temp[n] = NULL;
			temp[n] = ft_str_replace(temp[n], aux);
			printf("%s\n", temp[n]);
			n++;
		}
		else if (str[i] == SINGLE_QUOTE)
		{
			u = i;
			i++;
			while (str[i] != SINGLE_QUOTE)
				i++;
			aux = ft_calloc(sizeof(char *),
					(ft_strlen(str) - (i - u)) + 1);
			while (u <= i)
			{
				aux[c] = str[u];
				u++;
				c++;
			}
			c = 0;
			temp[n] = NULL;
			temp[n] = ft_str_replace(temp[n], aux);
			printf("%s\n", temp[n]);
			n++;
		}
		else
		{
			u = i;
			i++;
			while (str[i])
			{
				if ((str[i] == DOUBLE_QUOTE) || (str[i] == SINGLE_QUOTE))
				{
					i--;
					break ;
				}
				i++;
			}
			aux = ft_calloc(sizeof(char *),
					(ft_strlen(str) - (i - u)) + 1);
			while (u <= i)
			{
				aux[c] = str[u];
				u++;
				c++;
			}
			c = 0;
			temp[n] = NULL;
			temp[n] = ft_str_replace(temp[n], aux);
			printf("%s\n", temp[n]);
			n++;
		}
	}
	return (str);
}

int	parser_arg_num(char *str)
{
	int	n;
	int	i;
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
			n++;
			if ((size_t)i + 1 == ft_strlen(str))
				break ;
			i++;
			if (checker == 1)
			{
				while ((size_t)i != ft_strlen(str))
				{
					if (str[i] == 39)
						break ;
					i++;
				}
			}
			else
			{
				while ((size_t)i != ft_strlen(str))
				{
					if (str[i] == 34)
						break ;
					i++;
				}
			}
		}
		i++;
	}
	return (n);
}
