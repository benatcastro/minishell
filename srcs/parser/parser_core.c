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
=======
/*   Updated: 2022/09/29 14:17:20 by umartin-         ###   ########.fr       */
>>>>>>> parser quote norm
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
=======
		if (parser_quote_error_chk(str[i]))
			break ;
		aux = parser_quotes(str[i]);
>>>>>>> parser quote norm
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
