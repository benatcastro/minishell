/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:46:11 by aalvarez          #+#    #+#             */
/*   Updated: 2022/10/05 11:31:35 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"

/**
 * @brief appends a node to the back of the list pointed by lst.
 *
 * @param lst the head of the list.
 * @param new the node to be added to the back of the list.
 */
void	ft_cmdadd_back(t_command **lst, t_command *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_cmdlast(*lst);
		ft_cmdlast(*lst)->next = new;
	}
}

void	ft_tableadd_back(t_command_table **lst, t_command_table *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_tablelast(*lst);
		ft_tablelast(*lst)->next = new;
	}
}
