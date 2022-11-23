/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/11/23 18:33:43 by bena             ###   ########.fr       */
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
			aux1 = ft_strjoin_free(aux1, aux2);
		}
		i++;
	}
	free(cmds);
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
	while (++i < ((int)ft_strlen(str) - 1))
	{
		rtn[c] = str[i];
		c++;
	}
	return (free(str), rtn);
}

char	*expand_first_trimmer(char	*str)
{
	int		i;
	int		c;
	char	*rtn;

	i = 0;
	c = 0;
	rtn = ft_calloc(sizeof(char *), (ft_strlen(str) - 2));
	while (++i < ((int)ft_strlen(str)))
	{
		rtn[c] = str[i];
		c++;
	}
	return (rtn);
}

char	*untrimmer(char *str)
{
	char	*rtn;
	int		i;
	int		c;

	i = 1;
	c = -1;
	rtn = ft_calloc(sizeof(char), ft_strlen(str) + 3);
	rtn[0] = SINGLE_QUOTE;
	while (str[++c])
	{
		rtn[i] = str[c];
		i++;
	}
	rtn[i] = SINGLE_QUOTE;
	free(str);
	return (rtn);
}

char	**single_quote_expander(char **rtn)
{
	int		i;
	char	*aux;

	i = -1;
	while (rtn[++i])
	{
		if (rtn[i][0] == SINGLE_QUOTE)
		{
			aux = expand_trimmer(rtn[i]);
			aux = double_joiner(expander(aux));
			rtn[i] = untrimmer(aux);
		}
	}
	return (rtn);
}

char	*expander_main(char	*str)
{
	char	**rtn;
	char	*temp;
	char	*r;

	rtn = NULL;
	if (str[0] == SINGLE_QUOTE)
		return (expand_trimmer(str));
	else if (str[0] == DOUBLE_QUOTE)
	{
		temp = expand_trimmer(str);
		rtn = expander(temp);
	}
	else
		rtn = expander(str);
	rtn = single_quote_expander(rtn);
	r = double_joiner(rtn);
	if (rtn != NULL)
		ft_doublefree(rtn);
	return (r);
}

char	*double_joiner(char **temp)
{
	int		i;
	char	*aux;
	char	*rtn;

	i = 1;
	rtn = ft_strdup(temp[0]);
	while (temp[i])
	{
		aux = ft_strdup(temp[i]);
		rtn = ft_strjoin(rtn, aux);
		i++;
		if ((aux))
			free (aux);
	}
	return (rtn);
}