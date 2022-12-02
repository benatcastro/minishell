/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/02 14:52:03 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "signals.h"
#include "builtins.h"
#include <errno.h>

t_data	g_data;

void	readline_loop(char *buf, char **lex, char *tmp)
{
	while (1)
	{
		g_data.sub_pid = 0;
		free(tmp);
		buf = readline(PROMPT);
		if (!buf)
		{
			unlink(".temp");
			break ;
		}
		tmp = ft_strtrim(buf, " ");
		if (buf[0] == '\0' || !tmp[0])
			continue ;
		add_history(buf);
		if (parser_quote_error_chk(buf) != 0)
			continue ;
		lex = parser_core(lex_core(buf));
		if (global_error_chkr(lex))
		{
			glob_err_chckr_error(buf, lex);
			continue ;
		}
		free (buf);
		executor_core(lex);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*buf;
	char	**lex;
	char	*tmp;

	buf = NULL;
	lex = NULL;
	tmp = NULL;
	if (argc != 1)
		return (0);
	argv = NULL;
	g_data.ms_pid = get_pid();
	g_data.env = ft_doublestrdup(env);
	g_data.exit_val = 0;
	rebuild_env("OLDPWD");
	rl_catch_signals = 0;
	signal(SIGINT, signal_reciever);
	signal(SIGQUIT, signal_reciever);
	readline_loop(buf, lex, tmp);
	exit_builtin(NULL, 0);
	return (g_data.exit_val);
}
