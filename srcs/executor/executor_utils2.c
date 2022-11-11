/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:32:42 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/11 01:15:48 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

int	first_pipe_op(t_command *temp, int fd[2], char **env, int *pid)
{
	pid[0] = fork();
	if (pid[0] == 0)
	{
		redir_link(&temp, temp->args);
		dup2(fd[1], STDOUT_FILENO);
		close (fd[1]);
		redirection_core(temp, env);
	}
	return (0);
}

int	second_pipe_op(t_command *temp, int fd[2], char **env, int *pid)
{
	pid[1] = fork();
	if (pid[1] == 0)
	{
		redir_link(&temp, temp->args);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		redirection_core(temp, env);
	}
	close (fd[0]);
	return (0);
}

char	*ft_strdup_n_rem(const char *s1)
{
	char	*result;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) - 1));
	if (!result)
		return (NULL);
	i = -1;
	len = ft_strlen(s1) - 1;
	while (++i < len)
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}
