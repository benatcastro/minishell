/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:05 by bena              #+#    #+#             */
/*   Updated: 2022/10/21 10:40:24 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>


//Los args de esta funcion deberian de ser el input lexeado y parseado
//y la futura struct

int	builtin_checker(char **args, char **env)
{
	if (!ft_strncmp(args[0], "env", 4))
		return (1);
	else if (!ft_strncmp(args[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(args[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(args[0], "export", 7))
		return (1);
	else if (!ft_strncmp(args[0], "echo", 5))
		return (1);
	else
		return (0);
}

char	*env_path_maker(char *val, char **env, int *i)
{
	int	r;
	int	n;

	n = 4;
	r = 0;
	while (env[*i][++n])
		val[r++] = env[*i][n];
	val[r] = 0;
	return (val);
}

static char	*bin_path_finder(char **args, char **env)
{
	char	*path;
	char	*temp;
	char	**p;
	int		i;

	i = -1;
	while (env[++i])
	{
		if ((!ft_strncmp("PATH", env[i], 4)))
		{
			temp = ft_calloc(sizeof(char *),
					(ft_strlen(env[i]) - 5));
			temp = env_path_maker(temp, env, &i);
			break ;
		}
	}
	p = ft_split_exec(temp, 58);
	i = -1;
	temp = NULL;
	while (p[++i])
	{
		temp = ft_strjoin(p[i], args[0]);
		if (!access(temp, X_OK))
			return (temp);
	}
	return (temp = NULL, temp);
}

static char	*bin_executor(char **args, char **env)
{
	char	*path;

	path = bin_path_finder(args, env);
	if (path != NULL)
		execve(path, args, env);
	return (path);
}

static int	execute_cmds(t_command_table *cmd, char **args, char **env)
{
	if (builtin_checker(args, env))
		builtins(cmd, env);
	else
		bin_executor(args, env);
	exit(1);
}

t_args	*ft_lstnew_double(char **content)
{
	t_args	*node;

	node = (t_args *)malloc(sizeof(t_args));
	if (!node)
		return (NULL);
	node->cont = ft_doublestrdup(content);
	node->next = NULL;
	return (node);
}

static void	list_args(t_args **head, char **cmds)
{
	char	**temp;
	int		i;
	int		m;
	int		l;

	i = -1;
	m = 0;
	while (cmds[++i])
	{
		if (ft_strcmp(cmds[i], PIPE))
		{
			l = 0;
			temp = malloc(sizeof(char **) * (i - m));
			while (m < i)
				temp[l++] = ft_strdup(cmds[m++]);
			temp[l] = 0;
			ft_lstadd_back(head, ft_lstnew_double(temp));
			ft_doublefree(temp);
		}
	}
	l = 0;
	temp = malloc(sizeof(char **) * (i - m) + 1);
	while (m < i)
		temp[l++] = ft_strdup(cmds[m++]);
	temp[l] = 0;
	ft_lstadd_back(head, ft_lstnew_double(temp));
	ft_doublefree(temp);
}

void pipes

int	executor_core(char **cmd, char **env)
{
	t_args	*cmds;
	pid_t			f;
	pid_t			f2;
	int				fd[2];
	int				i;

	cmds = NULL;
	list_args(&cmds, cmd);
	ft_doubleprint(cmds->next->cont);
	i = 0;
	temp = cmd_table;
	while (temp->cmds[0]->next != NULL)
	{
		temp = temp->cmds[0]->next;
		i++;
	}
	temp = cmd_table;
	printf ("I = %d\n", i);
	if (pipe (fd) == -1)
		exit (0);
	f = fork();
	if (f == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute_cmds(cmd_table, temp->cmds[0]->args, env);
	}
	temp = temp->cmds[0]->next;
	f = fork();
	if (f == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute_cmds(cmd_table, temp->cmds[0]->args, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(f, NULL, 0);
	waitpid(f2, NULL, 0);
	return (1);
}
