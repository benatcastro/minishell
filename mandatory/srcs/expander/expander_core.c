/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 19:15:08 by umartin-         ###   ########.fr       */
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
	r = double_joiner(rtn);
	ft_doublefree(rtn);
	return (r);
}
