/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/29 13:54:30 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

int	main(int argc, char **argv, char **env)
{
	char	*buf;
	char	**lex;
	t_list	*args;
	int		i;

	(void)argc;
	(void)argv;
	args = NULL;
	buf = NULL;
	lex = NULL;
	i = 0;
	//signals_core(); //uncomment when signals are ready
	while (1)
	{
		buf = readline(PROMPT);
		if (buf == NULL || buf[0] == '\0')
			continue ;
		if (!buf)
			continue ;
		add_history(buf);
		lex = lexer_core(buf);
		lex = parser_core(lex);
		builtins(buf, env);
		free (buf);
	}
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

int	ft_quote_checker(char *buf)
{
	int		c;
	int		i;

	i = -1;
	c = 0;
	while (buf[++i])
	{
		if (buf[i] == 34)
			c++;
	}
	if ((c / 2 != 1) || (c / 2 == 0))
	{
		printf ("Invalid Quotes");
		return (0);
	}
	return (1);
}

void	builtins(char *buf, char **env)
{
	int		i;
	char	*pwd_dir;

	i = -1;
	if (!ft_strncmp(buf, "env", 4))
	{
		while (env[++i])
			printf ("%s\n", env[i]);
	}
	else if (!ft_strncmp(buf, "pwd", 4))
	{
		pwd_dir = getcwd(NULL, 0);
		printf("%s\n", pwd_dir);
		free(pwd_dir);
	}
	else if (!ft_strncmp(buf, "exit", 5))
	{
		printf ("exit\n");
		exit (0);
	}
	else if (!ft_strncmp(buf, "export", 7))
	{
		ft_export_no_arg(env);
	}
	else
		printf ("\033[33mBender 🤖: \033[0m%s: command not found\n", buf);
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
