/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:48:40 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:19 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"

char	**temp_utis_pipe(char *rtn)
{
	char	**temp;
	char	*t1;
	char	*t2;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	c = 0;
	t1 = ft_calloc(2, sizeof(char));
	t1[0] = '|';
	t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
	while (rtn[++c])
		t2[c - 1] = rtn[c];
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	return (free(t1), free(t2), temp);
}

char	**temp_utis_less(char *rtn)
{
	char	**temp;
	char	*t1;
	char	*t2;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	c = 0;
	t1 = ft_calloc(2, sizeof(char));
	t1[0] = '<';
	t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
	while (rtn[++c])
		t2[c - 1] = rtn[c];
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	return (free(t1), free(t2), temp);
}

char	**temp_utis_doubleless(char *rtn)
{
	char	**temp;
	char	*t1;
	char	*t2;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	c = 1;
	t1 = ft_calloc(3, sizeof(char));
	t1[0] = '<';
	t1[1] = '<';
	t2 = ft_calloc(ft_strlen(rtn) - 1, sizeof(char));
	while (rtn[++c])
		t2[c - 2] = rtn[c];
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	return (free(t1), free(t2), temp);
}

char	**temp_utis_greater(char *rtn)
{
	char	**temp;
	char	*t1;
	char	*t2;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	c = 0;
	t1 = ft_calloc(2, sizeof(char));
	t1[0] = '>';
	t2 = ft_calloc(ft_strlen(rtn), sizeof(char));
	while (rtn[++c])
		t2[c - 1] = rtn[c];
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	return (free(t1), free(t2), temp);
}

char	**temp_utis_doublegreater(char *rtn)
{
	char	**temp;
	char	*t1;
	char	*t2;
	int		c;

	temp = ft_calloc(3, sizeof(char *));
	c = 1;
	t1 = ft_calloc(3, sizeof(char));
	t1[0] = '>';
	t1[1] = '>';
	t2 = ft_calloc(ft_strlen(rtn) - 1, sizeof(char));
	while (rtn[++c])
		t2[c - 2] = rtn[c];
	temp[0] = ft_strdup(t1);
	temp[1] = ft_strdup(t2);
	return (free(t1), free(t2), temp);
}
