/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/11/21 17:19:50 by umartin-         ###   ########.fr       */
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
	return (rtn);
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
		if (str)
			free (str);
		if (temp)
			free (temp);
	}
	else
		rtn = expander(str);
	r = double_joiner(rtn);
	//ft_doublefree(rtn);
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
