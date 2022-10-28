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

static char	*ft_strdup_g(char *s)
{
	char	*result;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s[len] != '\0')
		len++;
	result = malloc(sizeof(*s) * len + 1);
	if (result == NULL)
		return (NULL);
	while (s[++i])
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

static char	*get_next_line(int fd)
{
	char	buffer;
	char	rtn[7000000];
	int		n;
	int		i;

	// if (fd < 0 || BUFFER_SIZE <= 0)
	// 	return (0);
	i = 0;
	n = read(fd, &buffer, 1);
	while (n > 0)
	{
		rtn[i++] = buffer;
		if (buffer == '\n')
			break ;
		n = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (n <= 0 && i == 0)
		return (0);
	return (ft_strdup_g(rtn));
}

void	gnl_main(fd)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
}

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

void	execute_cmds(t_args **cmd, char **args, char **env)
{
	if (builtin_checker(args, env))
		builtins(cmd, env);
	else
		bin_executor(args, env);
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

t_args	*ft_lstlast_args(t_args *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_args(t_args **lst, t_args *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast_args(*lst)->next = new;
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
			temp = malloc(sizeof(char *) * (i - m));
			while (m < i)
				temp[l++] = ft_strdup(cmds[m++]);
			m++;
			temp[l] = 0;
			ft_lstadd_back_args(head, ft_lstnew_double(temp));
		}
	}
	l = 0;
	temp = malloc(sizeof(char **) * (i - m) + 1);
	while (m < i)
		temp[l++] = ft_strdup(cmds[m++]);
	temp[l] = 0;
	ft_lstadd_back_args(head, ft_lstnew_double(temp));
}

void exec_nopipe(t_args **cmd, char **env)
{
	t_args	*temp;
	int		n;
	pid_t	pid;
	int		fd[2];
	int		status;

	temp = *cmd;
	if (pipe (fd) == -1)
		exit (0);
	pid = fork();
	if (pid == 0)
		execute_cmds(cmd, temp->cont, env);
	else
		wait (0);
}

void exec_onepipe(t_args **cmd, char **env)
{
	t_args	*temp;
	int		n;
	pid_t	pid[2];
	int		fd[2];
	int		status;

	temp = *cmd;
	if (pipe (fd) == -1)
		exit (0);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		n = 0;
		while (n++ < 2)
			close (fd[n]);
		execute_cmds(cmd, temp->cont, env);
	}
	temp = temp->next;
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		n = 0;
		while (n++ < 2)
			close (fd[n]);
		execute_cmds(cmd, temp->cont, env);
	}
	n = 0;
	while (n++ < 2)
		close (fd[n]);
	n = 0;
	while (n++ < 2)
		waitpid(pid[n], &status, 0);
}

void pipe_core(t_args **cmd, char **env)
{
	t_args	*temp;
	int		n;
	pid_t	pid[3];
	int		fd[2];
	int		fd2[2];
	int		i;
	int 	status;

	i = 1;
	temp = *cmd;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i == 1)
		exec_nopipe(cmd, env);
	else if (i == 2)
		exec_onepipe(cmd, env);
	else
	{
		temp = *cmd;
		if (pipe (fd) == -1)
			exit (0);
		if (pipe (fd2) == -1)
			exit (0);
		pid[0] = fork();
		if (pid[0] == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			n = 0;
			while (n < 2)
			{
				close (fd[n]);
				close (fd2[n]);
				n++;
			}
			execute_cmds(cmd, temp->cont, env);
		}
		temp = temp->next;
		i--;
		while (i > 1)
		{
			pid[1] = fork();
			if (pid[1] == 0)
			{
				dup2(fd[0], STDIN_FILENO);
				dup2(fd2[1], STDOUT_FILENO);
				n = 0;
				while (n < 2)
				{
					close (fd[n]);
					close (fd2[n]);
					n++;
				}
				execute_cmds(cmd, temp->cont, env);
			}
			temp = temp->next;
			i--;
		}
		pid[2] = fork();
		if (pid[2] == 0)
		{
			dup2(fd2[0], STDIN_FILENO);
			n = 0;
			while (n < 2)
			{
				close (fd[n]);
				close (fd2[n]);
				n++;
			}
			execute_cmds(cmd, temp->cont, env);
		}
		n = 0;
		while (n < 2)
		{
			close (fd[n]);
			close (fd2[n]);
			n++;
		}
		n = 0;
		while (n < 3)
		{
			waitpid(pid[n], &status, 0);
			n++;
		}
	}
}

int	executor_core(char **cmd, char **env)
{
	t_args	*cmds;

	cmds = NULL;
	list_args(&cmds, cmd);
	// ft_doubleprint(cmds->cont);
	// ft_doubleprint(cmds->next->cont);
	pipe_core(&cmds, env);
	return (1);
}
