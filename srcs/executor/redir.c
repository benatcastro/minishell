/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:38:01 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/29 21:12:25 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>

t_red	*ft_lstnew_double(char **content)
{
	t_red	*node;

	node = (t_red *)malloc(sizeof(t_red));
	if (!node)
		return (NULL);
	node->cont = ft_doublestrdup(content);
	node->next = NULL;
	return (node);
}

t_red	*ft_lstlast_red(t_red *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_red(t_red **lst, t_red *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast_red(*lst)->next = new;
}

void	redirection_in(char	**args)
{
	t_red	*in;
	char	**temp;
	int		i;

	i = -1;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
		{
			temp = malloc(sizeof(char *) * 3);
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			ft_lstadd_back_red(&in, ft_lstnew_double(temp));
		}
	}
}

void	redirection_out(char	**args)
{
	t_red	*in;
	t_red	*out;
	char	**temp;
	int		i;

	i = -1;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER)))
		{
			temp = malloc(sizeof(char *) * 3);
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			ft_lstadd_back_red(&out, ft_lstnew_double(temp));
		}
		if ((ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
		{
			temp = malloc(sizeof(char *) * 3);
			temp[0] = ft_strdup(args[i]);
			temp[1] = ft_strdup(args[i + 1]);
			temp[2] = 0;
			ft_lstadd_back_red(&in, ft_lstnew_double(temp));
		}
	}
}
