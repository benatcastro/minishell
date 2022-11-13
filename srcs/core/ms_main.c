/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/13 05:46:04 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "signals.h"
#include "builtins.h"


int	main(int argc, char **argv, char **env)
{
	char	*buf;
	char	**en;
	char	**lex;
	int		i;

	(void)argc;
	(void)argv;
	buf = NULL;
	lex = NULL;
	en = ft_doublestrdup(env);
	i = 0;
	g_data.ms_pid = get_pid();
	rl_catch_signals = 0;
	signals_core(); //uncomment when signals are ready
	while (1)
	{
		buf = readline(PROMPT);
		if (!buf)
			exit_builtin();
		add_history(buf);
		if (parser_quote_error_chk(buf))
			continue ;
		lex = lex_core(buf);
		lex = parser_core(lex, en);
		i = 0;
		if (global_error_chkr(lex))
			continue ;
		executor_core(lex, en);
		free (buf);
	}
	printf("FREE TEST\n");
	return (0);
}

int	global_error_chkr(char	**lex)
{
	int	i;

	if (!lex || lex[0] == NULL)
		return (-1);
	if (ft_strcmp(lex[0], "<PIPE>"))
		return (1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if ((lex[i + 1] && ft_strcmp(lex[i + 1], GREATER))
				|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLEGREATER))
				|| (lex[i + 1] && ft_strcmp(lex[i + 1], LESS))
				|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLELESS)))
				return (-1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if (lex[i + 1] == NULL)
				return (-1);
	if (ft_strcmp (lex[ft_doublestrlen(lex) - 1], PIPE))
		return (1);
	return (0);
}

int	ft_strlen_sh(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
