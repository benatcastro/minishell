/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:26:42 by bena              #+#    #+#             */
/*   Updated: 2022/10/05 12:30:38 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include "libft.h"
#include "nodes.h"

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

t_command	**create_cmd(char **cmds)
{
	t_command	**cmds_head;

	cmds_head = NULL;
	ft_cmdadd_back(cmds_head, create_cmd_node(cmds));
	return (cmds_head);

}

t_command_table	*create_command_table_node(char **cmds)
{
	t_command_table		*node;
	static unsigned int	key;

	node = ft_calloc(1, sizeof(t_command_table));
	ft_memset(node, 0, sizeof(t_command_table));
	node->key = key;
	key++;
	node->cmds = create_cmd(cmds);
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
