/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:25:30 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/29 19:32:12 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>

t_args	*ft_lstnew_double(char **content)
{
	t_args	*node;

	node = (t_args *)malloc(sizeof(t_args));
	if (!node)
		return (NULL);
	node->cont = ft_doublestrdup(content);
	node->next = NULL;
	//ft_doublefree(content);
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

void	list_args( **head, char **cmds)
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
			temp = malloc(sizeof(char *) * (i - m));
			while (m < i)
				temp[l++] = ft_strdup(cmds[m++]);
			m++;
			temp[l] = 0;
			ft_lstadd_back_args(head, ft_lstnew_double(temp));
		}
		l = 0;
	}
	temp = malloc(sizeof(char **) * (i - m) + 1);
	while (m < i)
		temp[l++] = ft_strdup(cmds[m++]);
	temp[l] = 0;
	ft_lstadd_back_args(head, ft_lstnew_double(temp));
}
