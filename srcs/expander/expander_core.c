/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/10/01 17:41:20 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	*expander_core(char **cmds, char **env)
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
			aux1 = expander_main(cmds[i], env);
		else if (aux1)
		{
			aux2 = expander_main(cmds[i], env);
			aux1 = ft_strjoin(aux1, aux2);
		}
		i++;
	}
	return (aux1);
}

char	*expand_trimmer(char	*str)
{
	int		i;
	int		c;
	char	*rtn;

	i = 0;
	c = 0;
	rtn = ft_calloc(sizeof(char *), (ft_strlen(str) - 1));
	while (++i < (ft_strlen(str) - 1))
	{
		rtn[c] = str[i];
		c++;
	}
	rtn[i] = 0;
	return (rtn);
}

char	*expander_main(char	*str, char **env)
{
	char	*rtn;
	int		i;
	int		c;

	rtn = NULL;
	i = -1;
	if (str[0] == SINGLE_QUOTE)
		rtn = expand_trimmer(str);
	else if (str[0] == DOUBLE_QUOTE)
		rtn = expander(expand_trimmer(str), env);
	else
		rtn = expander(str, env);
	return (rtn);
}

char	*expander(char	*str, char **env)
{
	int		i;
	int		n;
	char	**temp;

	temp = malloc(sizeof(char *) * (expand_arg_num(str)) + 1);
	temp = expand_splitter(str);
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

int	expand_arg_num(char *str)
{
	int		e;
	int		c;

	e = -1;
	c = 0;
	while (str[++e])
	{
		if (str[e] == 36)
		{
			c++;
			e += 2;
			while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
				e++;
			e--;
		}
		else
		{
			c++;
			while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
				e++;
			e--;
		}
	}
	return (c);
}

char	**expand_splitter(char *str)
{
	int		e;
	int		l;
	int		c;

	e = 0;
	c = 0;
	while (str[e])
	{
		if (str[e] == 36)
		{
			l = 0;
			e += 2;
			while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
				e++;
			e--;
		}
		else
		{
			l = 0;
			while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
				e++;
			e--;
		}
		e++;
	}
	return (c);
}
