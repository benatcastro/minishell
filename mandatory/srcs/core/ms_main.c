/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 17:46:44 by umartin-         ###   ########.fr       */
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
		free(tmp);
		buf = readline(PROMPT);
		if (!buf)
			break ;
		tmp = ft_strtrim(buf, " ");
		if (buf[0] == '\0' || !tmp[0])
			continue ;
		add_history(buf);
		if (parser_quote_error_chk(buf) != 0)
			continue ;
		lex = parser_core(lex_core(buf));
		if (global_error_chkr(lex))
		{
			printf ("BASHado: syntax error\n");
			g_data.exit_val = 258;
			free (buf);
			ft_doublefree(lex);
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
	signals_core();
	readline_loop(buf, lex, tmp);
	exit_builtin(NULL, 0);
	return (g_data.exit_val);
}

int	global_error_chkr_ut(char	**lex, int i)
{
	if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
		|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
		if ((lex[i + 1] && ft_strcmp(lex[i + 1], GREATER))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLEGREATER))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], LESS))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLELESS))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], PIPE))
			|| (lex[i + 1] && ft_strcmp(lex[i + 1], DOUBLEPIPE)))
			return (-1);
	if ((ft_strcmp(lex[i], PIPE)) || (ft_strcmp(lex[i], DOUBLEPIPE)))
		if (!lex[i + 1] || (ft_strcmp(lex[i + 1], PIPE))
			|| (ft_strcmp(lex[i + 1], DOUBLEPIPE)))
			return (-1);
	if ((ft_strcmp(lex[i], DOUBLEAMPERSAND)) || (ft_strcmp(lex[i], DOUBLEPIPE)))
		return (-1);
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
		if (global_error_chkr_ut(lex, i) == -1)
			return (-1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if (lex[i + 1] == NULL)
				return (-1);
	i = -1;
	while (lex[++i])
		if ((ft_strcmp(lex[i], SEMICOLON)) || (ft_strcmp(lex[i], "ASCII92")))
			return (-1);
		i = -1;
	while (lex[++i])
		if ((lex[i][0] == '<' || lex[i][0] == '>')
			&& (lex[i][1] == '<' || lex[i][1] == '>' || lex[i][1] == '|'))
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
