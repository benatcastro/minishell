/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:26:42 by bena              #+#    #+#             */
/*   Updated: 2022/11/25 05:14:54 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include "libft.h"
#include "nodes.h"
#include "lexer.h"

t_command_table	*create_command_table_node(char **cmds)
{
	t_command_table		*node;
	static unsigned int	key;

	node = ft_calloc(1, sizeof(t_command_table));
	ft_memset(node, 0, sizeof(t_command_table));
	node->cmds = ft_calloc(1, sizeof(t_command));
	ft_memset(node->cmds, 0, sizeof(t_command));
	node->key = key;
	key++;
	create_cmd(node->cmds, cmds);
	return (node);
}

t_command_table	**create_command_table(t_command_table **head, char **cmds)
{
	int	i;

	i = -1;
	if (!(*head))
		(*head) = create_command_table_node(cmds);
	while (cmds[++i])
		if (ft_strcmp(cmds[i], DOUBLEAMPERSAND)
			|| ft_strcmp(cmds[i], DOUBLEPIPE))
			ft_tableadd_back(head, create_command_table_node(&cmds[i + 1]));
	return (head);
}

t_command	*create_cmd_node(char **cmds)
{
	t_command			*node;
	static unsigned int	key;

	node = ft_calloc(1, sizeof(t_command));
	node->in = NULL;
	node->out = NULL;
	ft_memset(node, 0, sizeof(t_command));
	fill_cmd(node, cmds);
	node->key = key;
	key++;
	return (node);
}

t_command	**create_cmd(t_command **cmd_head, char **cmds)
{
	int	i;

	i = -1;
	if (!(*cmd_head))
		ft_cmdadd_back(cmd_head, create_cmd_node(cmds));
	while (cmds[++i])
		if (ft_strcmp(cmds[i], PIPE))
			ft_cmdadd_back(cmd_head, create_cmd_node(&cmds[i + 1]));
	return (cmd_head);
}

t_redir	*create_redir_node(char **content)
{
	t_redir	*node;

	node = ft_calloc(1, sizeof(t_redir));
	ft_memset(node, 0, sizeof(t_redir));
	node->content = content;
	return (node);
}
