/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:46:05 by bena              #+#    #+#             */
/*   Updated: 2022/09/26 18:35:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("(%s)\n ", str[i]);
}

static int	replace_for_keywords(char **str, char **cmd)
{
	int	i;

	(void)cmd;
	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "&"))
			str[i] = ft_str_replace(str[i], AMPERSAND);
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

int	lexer_core(char	*cmd)
{
	char	**str;
	char	**cmd_splitted;

	cmd_splitted = ft_split_in_set(cmd, "'");
	str = ft_split_in_set(cmd, WHITESPACE);
	print_double_str(cmd_splitted);
	printf("===After lexing====\n");
	replace_for_keywords(str, cmd_splitted);
	print_double_str(str);
	//Here goes call to parser (maybe)
	return (1);
}
