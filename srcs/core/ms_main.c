/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/12 14:11:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

t_data	g_data;

int	main(int argc, char **argv, char **env)
{
	char	*buf;
	char	**en;
	char	**lex;
	t_list	*args;
	int		i;

	(void)argc;
	(void)argv;
	args = NULL;
	buf = NULL;
	lex = NULL;
	en = ft_doublestrdup(env);
	i = 0;
	signals_core(); //uncomment when signals are ready
	while (1)
	{
		buf = readline(PROMPT);
		if (buf == NULL || buf[0] == '\0')
			continue ;
		if (!buf)
			continue ;
		add_history(buf);
		if (parser_quote_error_chk(buf))
			exit (0);
		lex = lex_core(buf);
		lex = parser_core(lex, en);
		i = 0;
		if (global_error_chkr(lex))
			continue ;
		//ft_doublefree (lex);
		executor_core(lex, en);
		free (buf);
	}
	printf("FREE TEST\n");
	return (0);
}

int	global_error_chkr(char	**lex)
{
	int i;

	if (ft_strcmp(lex[0], "<PIPE>"))
		return (1);
	i = -1;
	while (lex[++i])
	{
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if ((ft_strcmp(lex[i + 1], GREATER))
				|| (ft_strcmp(lex[i + 1], DOUBLEGREATER))
				|| (ft_strcmp(lex[i + 1], LESS))
				|| (ft_strcmp(lex[i + 1], DOUBLELESS)))
				return (-1);
	}
	i = -1;
	while (lex[++i])
	{
		if ((ft_strcmp(lex[i], GREATER)) || (ft_strcmp(lex[i], DOUBLEGREATER))
			|| (ft_strcmp(lex[i], LESS)) || (ft_strcmp(lex[i], DOUBLELESS)))
			if (lex[i + 1] == NULL)
				return (-1);
	}
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

void	ft_export_no_arg(char **cln)
{
	int		i;
	int		f;
	int		c;
	int		e;
	char	*aux;
	char	**env;

	env = ft_doublestrdup(cln);
	e = 0;
	f = 0;
	while (e != ft_doublestrlen(env) - 1)
	{
		i = e;
		c = i;
		while (i != ft_doublestrlen(env) - 1)
		{
			i++;
			if (env[i][f] < env[c][f])
				c = i;
			else if (env[i][f] == env[c][f])
			{
				i--;
				f++;
				continue ;
			}
			f = 0;
		}
		aux = env[e];
		env[e] = env[c];
		env[c] = aux;
		e++;
	}
	i = 0;
	while (env[++i])
		printf ("%s\n", env[i]);
}
