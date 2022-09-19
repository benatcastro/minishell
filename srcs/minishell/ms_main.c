/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/19 16:19:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*cr;
	char	*buf;

	(void)argc;
	(void)argv;
	cr = NULL;
	buf = NULL;
	while (1)
	{
		cr = readline("\033[33mJarvis 🤖 > \033[0m");
		if (cr == NULL || cr[0] == '\0')
			continue ;
		//buf = ft_quote_checker(cr);
		//printf ("%s\n", buf);
		if (!cr)
			continue ;
		add_history(cr);
		builtins(cr, env);
		free (cr);
	}
	return (0);
}

char	*ft_quote_checker(char *buf)
{
	int		c;
	int		i;
	char	*rtn;

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
		return (NULL);
	}
	rtn = malloc(sizeof(buf) * ft_strlen(buf) - c + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (buf[i])
	{
		if (buf[i] != 34)
		{
			rtn[c] = buf[i];
			c++;
			i++;
		}
		else
			i++;
	}
	rtn[c] = '\0';
	return (rtn);
}

void	builtins(char *buf, char **env)
{
	int		i;
	char	*pwd_dir;

	i = -1;
	pwd_dir = malloc(sizeof (char *) * 1024);
	if ((!ft_strncmp(buf, "env", ft_strlen(buf))) && ft_strlen(buf) == 3)
	{
		while (env[++i])
			printf ("%s\n", env[i]);
	}
	else if ((!ft_strncmp(buf, "pwd", ft_strlen(buf))) && ft_strlen(buf) == 3)
	{
		if (getcwd(pwd_dir, 1024) != NULL)
			fprintf(stdout, "%s\n", pwd_dir);
		free(pwd_dir);
	}
	// else if (!ft_strncmp(buf, "echo", 4))
	// 	ft_echo(buf);
	else if ((!ft_strncmp(buf, "exit", ft_strlen(buf))) && ft_strlen(buf) == 4)
	{
		printf ("exit\n");
		exit (0);
	}
	else
		printf ("\033[33mJarvis 🤖: \033[0m%s: command not found\n", buf);
}

// void	ft_echo(char *str)
// {
// 	int	c;
// }
