/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/09/29 20:36:01 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	*expander_core(char **cmds)
{
	int		i;
	char	*aux1;
	char	*aux2;

	i = 0;
	aux1 = NULL;
	aux2 = NULL;
	while (i <= (ft_doublestrlen(cmds) - 1))
	{
		if (!aux1)
			aux1 = expander_main(cmds[i]);
		else if (aux1)
		{
			aux2 = expander_main(cmds[i]);
			aux1 = ft_strjoin(aux1, aux2);
		}
		i++;
	}
	return (aux1);
}

char	*expander_main(char	*str)
{
	char	*rtn;
	int		i;

	rtn = NULL;
	i = 0;
	if (str[0] == SINGLE_QUOTE)
		rtn = ft_strtrim(str, "'");
	else if (str[0] == DOUBLE_QUOTE)
	{
		while (str[i])
		{
			if (str[i] == 36)
			{
				//rtn = expander(str);
				rtn = ft_strtrim(str, "\"");
				break ;
			}
			rtn = ft_strtrim(str, "\"");
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i] == 36)
			{
				//rtn = expander(str);
				break ;
			}
			rtn = ft_strtrim(str, "\"");
		}
	}
	return (rtn);
}

// char	*expand_splitter(char *str)
// {
// 	int		i;
// 	int		n;
// 	char	**temp;

// 	temp = malloc(sizeof(char *) * (parser_arg_num(str)) + 1);
// 	temp[(expander_arg_num(str))] = NULL;
// 	i = -1;
// 	n = 0;
// 	while (++i <= ((int)ft_strlen(str) - 1))
// 	{
// 		if (str[i] == DOUBLE_QUOTE)
// 			parser_double_q(str, temp, &i, &n);
// 		else if (str[i] == SINGLE_QUOTE)
// 			parser_single_q(str, temp, &i, &n);
// 		else
// 			parser_no_q(str, temp, &i, &n);
// 	}
// 	return (temp);
// }

// int	expand_arg_num(char *str)
// {
// 	int	n;
// 	int	i;

// 	i = 0;
// 	n = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 36)
// 			expand_arg_num_ut(str, &i, &n);
// 		i++;
// 	}
// 	return (n);
// }

// void	expand_arg_num_ut(char *str, int *i, int *n)
// {
// 	int	checker;

// 	(*n)++;
// 	if (*i + 1 == (int)ft_strlen(str))
// 		return ;
// 	(*i)++;
// 	while ((*i)++ != (int)ft_strlen(str))
// 		if ((str[*i] == 32) || (str[*i] == 36))
// 			break ;
// }
