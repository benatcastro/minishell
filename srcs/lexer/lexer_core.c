/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:46:05 by bena              #+#    #+#             */
/*   Updated: 2022/10/01 15:39:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("(%s)\n", str[i]);
}

static int	replace_for_keywords(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "&"))
			str[i] = ft_str_replace(str[i], AMPERSAND);
		else if (ft_strcmp(str[i], "&&"))
			str[i] = ft_str_replace(str[i], DOUBLEAMPERSAND);
		else if (ft_strcmp(str[i], "|"))
			str[i] = ft_str_replace(str[i], PIPE);
		else if (ft_strcmp(str[i], "||"))
			str[i] = ft_str_replace(str[i], DOUBLEPIPE);
		else if (ft_strcmp(str[i], ">"))
			str[i] = ft_str_replace(str[i], GREATER);
		else if (ft_strcmp(str[i], ">>"))
			str[i] = ft_str_replace(str[i], DOUBLEGREATER);
		else if (ft_strcmp(str[i], "<"))
			str[i] = ft_str_replace(str[i], LESS);
		else if (ft_strcmp(str[i], "<<"))
			str[i] = ft_str_replace(str[i], DOUBLELESS);
		else if (ft_strcmp(str[i], ";"))
			str[i] = ft_str_replace(str[i], SEMICOLON);
	}
	return (1);
}

char	**lexer_core(char	*cmd)
{
	char	**str;
	char	*cmd_dup;

	cmd_dup = ft_strdup(cmd);
	quote_logic(cmd_dup);
	str = ft_split_in_set(cmd_dup, WHITESPACE);
	// print_double_str(str);
	printf("===After lexing====\n");
	replace_for_spaces(str);
	replace_for_keywords(str);
	print_double_str(str);
	return (str);
}
