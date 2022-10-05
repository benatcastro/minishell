/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:26:42 by bena              #+#    #+#             */
/*   Updated: 2022/10/05 16:09:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include "libft.h"
#include "nodes.h"

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
			ft_tableadd_back(head, create_command_table_node(cmds));
	print_table(head);
	return (head);
}

t_command	*create_cmd_node(char **cmds)
{
	t_command			*node;
	static unsigned int	key;

	node = ft_calloc(1, sizeof(t_command));
	ft_memset(node, 0, sizeof(t_command));
	node->key = key;
	key++;
	fill_cmd(node, cmds);
	return (node);
}

t_command	**create_cmd(t_command **cmd_head, char **cmds)
{
	ft_cmdadd_back(cmd_head, create_cmd_node(cmds));
	return (cmd_head);
}
