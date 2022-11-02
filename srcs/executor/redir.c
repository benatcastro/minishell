/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:38:01 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/02 22:01:14 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <unistd.h>

t_red	*ft_lstnew_double_red(char **content)
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

void	redirection_in(t_red *in, char	**args)
{
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
			ft_lstadd_back_red(&in, ft_lstnew_double_red(temp));
		}
	}
}

void	redirection_out(t_red *out, char	**args)
{
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
			ft_lstadd_back_red(&out, ft_lstnew_double_red(temp));
		}
	}
}

void	redirection_ag(t_red *ag, char	**args)
{
	char	**temp;
	int		i;
	int		e;
	int		a;

	i = -1;
	a = 0;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER))
			|| (ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
			i++;
		else
		{
			while ((args[i]) && ((ft_strcmp(args[i], GREATER) == 0)
					|| (ft_strcmp(args[i], DOUBLEGREATER) == 0)
					|| (ft_strcmp(args[i], LESS) == 0)
					|| (ft_strcmp(args[i], DOUBLELESS) == 0)))
			{
					a++;
					i++;
			}
		}
	}
	temp = (char **)malloc(sizeof(char *) * (a + 1));
	printf("A = %d\n", a);
	i = -1;
	e = 0;
	while (args[++i])
	{
		if ((ft_strcmp(args[i], GREATER))
			|| (ft_strcmp(args[i], DOUBLEGREATER))
			|| (ft_strcmp(args[i], LESS))
			|| (ft_strcmp(args[i], DOUBLELESS)))
			i++;
		else
		{
			while ((args[i]) && ((ft_strcmp(args[i], GREATER) == 0)
					|| (ft_strcmp(args[i], DOUBLEGREATER) == 0)
					|| (ft_strcmp(args[i], LESS) == 0)
					|| (ft_strcmp(args[i], DOUBLELESS) == 0)))
					temp[e++] = ft_strdup(args[i++]);
		}
	}
	printf("I = %d\n", i);
	printf("E = %d\n", e);
	temp[e + 1] = NULL;
	ft_doubleprint (temp);
	ft_lstadd_back_red(&ag, ft_lstnew_double_red(temp));
}

void redir_link(t_redirections *head, char **args)
{
	redirection_in(head->in, args);
	redirection_out(head->out, args);
	redirection_ag(head->ag, args);
}
