/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:38 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/27 18:14:35 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

char	**parser_core(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != ft_doublestrlen(str))
		str[i] = parser_quotes(str[i]);
}

char	*parser_quotes(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	str = ft_strtrim(str, 39);
	printf("%s\n", str);
}
