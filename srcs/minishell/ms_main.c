/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:44 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/23 22:34:41 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*buf;
	t_list	*args;
	int		i;

	(void)argc;
	(void)argv;
	args = NULL;
	buf = NULL;
	i = 0;
	while (1)
	{
		buf = readline("\033[33mJarvis 🤖 > \033[0m");
		if (buf == NULL || buf[0] == '\0')
			continue ;
		if (!buf)
			continue ;
		add_history(buf);
		buf = ft_parser(buf);
		// ft_list_add(&args, buf, i);
		// printf ("%s\n", args->content);
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

void	ft_list_add(t_list **args, char *str, int i)
{
	int		c;
	int		aux;
	int		j;
	char	*temp;

	c = i;
	j = 0;
	while (str[i] != 32 || str[i] != '\0')
		i++;
	aux = i - c;
	temp = malloc(sizeof(char *) * aux + 1);
	while (c <= i)
		temp[j++] = str[c++];
	ft_lstadd_back(args, ft_lstnew(temp));
	free(temp);
	if (i != ft_strlen_sh(str))
		ft_list_add(args, str, i);
	return ;
}

char	*ft_parser(char *str)
{
	char	*rtn;
	int		i;
	int		c;

	i = -1;
	c = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str[0] == 32)
	{
		while (str[++i] == 32)
			continue ;
	}
	while (str[i])
	{
		if (str[i] == 32)
		{
			while (str[i] == 32)
				i++;
			rtn[c++] = 32;
		}
		if (str[i] == 39)
		{
			while (str[i] != 39)
				rtn[c++] = str[i];
		}
		else
			rtn[c++] = str[i];
		i++;
	}
	return (rtn);
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
		printf ("\033[33mJarvis 🤖: \033[0m%s: command not found\n", buf);
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
