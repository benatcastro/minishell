/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/15 20:09:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "signals.h"
#include "builtins.h"
#include <errno.h>

void	readline_loop(void)
{
	char	*buf;
	char	**lex;
	char	*tmp;

	buf = NULL;
	lex = NULL;
	tmp = NULL;
	while (1)
	{
		free(tmp);
		buf = readline(PROMPT);
		if (!buf)
			break ;
		tmp = ft_strtrim(buf, " ");
		if (buf[0] == '\0' || !tmp[0])
			continue ;
		add_history(buf);
		if (parser_quote_error_chk(buf))
			continue ;
		lex = parser_core(lex_core(buf));
		if (global_error_chkr(lex))
			continue ;
		executor_core(lex);
		free (buf);
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (0);
	(void)argv;
	g_data.ms_pid = get_pid();
	g_data.env = ft_doublestrdup(env);
	g_data.exit_val = 0;
	rebuild_env("OLDPWD");
	rl_catch_signals = 0;
	signals_core();
	readline_loop();
	printf("exit\n");
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

// int	ft_strlen_sh(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
