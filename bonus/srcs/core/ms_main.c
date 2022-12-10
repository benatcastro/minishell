/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/10 16:14:09 by becastro         ###   ########.fr       */
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
		if (parser_q_error_chk(buf) != 0 || parser_paren_error_chk(buf) != 0)
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

void	arg_loop_error(char *buf, char **lex)
{
	printerr("%ssyntax error\n", PROMPT_ERR);
	g_data.exit_val = 258;
	free (buf);
	ft_doublefree(lex);
	exit (0);
}

void	arg_loop(char *buf, char **lex, char *tmp, char **str)
{
	int	i;

	buf = ft_strdup(str[2]);
	i = 2;
	while (str[++i])
	{
		buf = ft_strjoin(buf, " \0");
		buf = ft_strjoin(buf, str[i]);
	}
	if (!buf)
		exit (0);
	tmp = ft_strtrim(buf, " ");
	if (buf[0] == '\0' || !tmp[0])
		exit (0);
	add_history(buf);
	if (parser_q_error_chk(buf) != 0
		|| parser_paren_error_chk(buf) != 0)
		exit (0);
	lex = parser_core(lex_core(buf));
	if (global_error_chkr(lex))
		arg_loop_error(buf, lex);
	free (buf);
	executor_core(lex);
	exit (0);
}

int	main(int argc, char **argv, char **env)
{
	char	*buf;
	char	**lex;
	char	*tmp;

	buf = NULL;
	lex = NULL;
	tmp = NULL;
	g_data.ms_pid = get_pid();
	g_data.env = ft_doublestrdup(env);
	g_data.shell_path = getcwd(NULL, 0);
	g_data.exit_val = 0;
	rebuild_env("OLDPWD");
	rl_catch_signals = 0;
	if (argc != 1)
	{
		if (ft_strcmp(argv[1], "-c\0") == 0)
			return (0);
		else
			arg_loop(buf, lex, tmp, argv);
	}
	signal(SIGINT, signal_reciever);
	signal(SIGQUIT, signal_reciever);
	readline_loop(buf, lex, tmp);
	exit_builtin(NULL, 0);
	return (g_data.exit_val);
}
