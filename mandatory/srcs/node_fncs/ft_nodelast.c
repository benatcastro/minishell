/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodelast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:43:37 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:32 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"

/**
 * @brief returns a pointer to the lists last node.
 *
 * @param lst a pointer to the first node to be iterated.
 * @return t_list* the last node of the list.
 */
t_command	*ft_cmdlast(t_command *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_command_table	*ft_tablelast(t_command_table *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_redir	*ft_redirlast(t_redir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
