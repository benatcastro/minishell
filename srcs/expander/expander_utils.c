/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:19:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/01 13:18:38 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

int	expand_arg_num(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 36)
			expand_arg_num_ut(str, &i, &n);
		else
		{
			n++;
			while (i++ != (int)ft_strlen(str))
				if (str[i + 1] == 36)
					break ;
		}
		i++;
	}
	return (n);
}

void	expand_arg_num_ut(char *str, int *i, int *n)
{
	int	checker;

	(*n)++;
	if (*i + 1 == (int)ft_strlen(str))
		return ;
	(*i)++;
	while ((*i)++ != (int)ft_strlen(str))
		if ((str[*i] == 32) || (str[*i] == 36))
			break ;
}

void	exander_dollar_find(char *str, char **temp, int *i, int *n)
{
	int		u;
	int		c;
	char	*aux;

	u = *i;
	(*i)++;
	c = 0;
	if (str[*i] == 36)
	{
		aux = ft_calloc(sizeof(char), 3);
		aux[0] = 36;
		aux[1] = 36;
		aux[2] = 0;
		temp[*n] = NULL;
		temp[*n] = ft_str_replace(temp[*n], aux);
		(*i)++;
		(*n)++;
	}
	while (str[*i])
	{
		if ((str[*i] == 36) || (str[*i] == 32))
		{
			(*i)--;
			break ;
		}
		(*i)++;
	}
	aux = ft_calloc(sizeof(char *),
			((*i - u)) + 2);
	while (u <= *i)
		aux[c++] = str[u++];
	aux[c] = 0;
	temp[*n] = NULL;
	temp[*n] = ft_str_replace(temp[*n], aux);
	(*n)++;
}

void	expaner_no_dollar(char *str, char **temp, int *i, int *n)
{
	int		u;
	int		c;
	char	*aux;

	u = *i;
	(*i)++;
	c = 0;
	while (str[*i])
	{
		if (str[*i] == 36)
		{
			(*i)--;
			break ;
		}
		(*i)++;
	}
	aux = ft_calloc(sizeof(char *),
			((*i - u) + 1));
	while (u <= *i)
		aux[c++] = str[u++];
	aux[c] = 0;
	temp[*n] = NULL;
	temp[*n] = ft_str_replace(temp[*n], aux);
	(*n)++;
}
