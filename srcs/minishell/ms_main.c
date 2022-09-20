/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/20 18:21:55 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*buf;

	(void)argc;
	(void)argv;
	buf = NULL;
	while (1)
	{
		buf = readline("\033[33mJarvis 🤖 > \033[0m");
		if (buf == NULL || buf[0] == '\0')
			continue ;
		if (!buf)
			continue ;
		add_history(buf);
		builtins(buf, env);
		free (buf);
	}
	return (0);
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
	else if (!ft_strncmp(buf, "export", 4))
	{
		printf ("export");
	}
	else
		printf ("\033[33mJarvis 🤖: \033[0m%s: command not found\n", buf);
}

// char	**ft_export(char **env)
// {
// 	char	**rtn;
// 	(void)env;
// 	(void)	rtn;
// }
