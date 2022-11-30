/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:36:49 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 13:09:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "wildcards.h"
#include "minishell.h"
#include <unistd.h>
#include "nodes.h"
#include "builtins.h"

void	special_builtins(t_command *temp)
{
	char	**env;
	int		i;

	i = 0;
	env = ft_doublestrdup(g_data.env);
	if (!temp->args[0] || temp->next != NULL || temp->prev != NULL)
		i = 1;
	g_data.sub_pid = 1;
	if (ft_strcmp(temp->args[0], "cd"))
		cd_builtin(temp->args);
	else if (ft_strcmp(temp->args[0], "export"))
	{
		if (i == 1)
			return ((void)ft_doublefree(env));
		if (!temp->args[1])
			ft_export_no_arg(env);
		else
			ft_export_arg(temp->args);
	}
	else if (ft_strcmp(temp->args[0], "unset"))
		unset_builtin(temp->args, i);
	else if (ft_strcmp(temp->args[0], "exit"))
		exit_builtin(temp->args, i);
	ft_doublefree(env);
	g_data.sub_pid = 0;
}

void	ft_repiper(t_shell *shell)
{
	close(shell->fd[0][1]);
	close(shell->fd[0][0]);
	shell->fd[0][0] = shell->fd[1][0];
	shell->fd[0][1] = shell->fd[1][1];
	pipe(shell->fd[1]);
}

void	*ft_memset_shell(void *b, int c, size_t len)
{
	unsigned char	*aux;
	size_t			i;

	i = 0;
	aux = (unsigned char *)b;
	while (i < len)
		aux[i++] = c;
	return (aux);
}

void	child_pro(t_command *temp, t_shell *shell, int id)
{
	t_redir		*t_in;

	g_data.sub_pid = 1;
	redir_link(&temp, temp->args);
		t_in = temp->in;
	if (t_in != NULL)
		in_redirection(t_in, shell->fd[0]);
	if (id == 0 && t_in != NULL)
	{
		dup2(shell->fd[0][0], STDIN_FILENO);
		unlink(".temp");
	}
	if (id != 0)
		dup2(shell->fd[0][0], STDIN_FILENO);
	if (id != shell->np - 1)
		dup2(shell->fd[1][1], STDOUT_FILENO);
	fd_closer_shell(shell);
	redirection_core(temp);
	exit (1);
}

void	exec_morepipes(t_command **cmd_table)
{
	t_shell			*shell;
	t_command		*temp;
	int				i;

	i = -1;
	temp = (*cmd_table);
	shell = ft_calloc(1, sizeof(t_shell));
	ft_allocator(shell, temp);
	while (++i < shell->np)
	{
		close(shell->fd[0][1]);
		shell->pid = fork();
		if (shell->pid == 0)
			child_pro(temp, shell, i);
		else
		{
			special_builtins(temp);
			waitpid (shell->pid, &g_data.exit_val, 0);
			g_data.sub_pid = 0;
			ft_repiper(shell);
			temp = temp->next;
		}
	}
	fd_closer_shell(shell);
	free(shell);
}
