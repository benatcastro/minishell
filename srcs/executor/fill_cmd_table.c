/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:37 by becastro          #+#    #+#             */
/*   Updated: 2022/11/04 04:12:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "stdio.h"

size_t	count_args(char **args)
{
	size_t	argc;
	int		i;

	i = -1;
	argc = 0;
	while (args[++i])
	{
		if (ft_strcmp(args[i], PIPE)
			|| ft_strcmp(args[i], DOUBLEPIPE)
			|| ft_strcmp(args[i], DOUBLEAMPERSAND))
			break ;
		else
			argc++;
	}
	return (argc);
}

void	fill_cmd(t_command *node, char **cmds)
{
	size_t		argc;
	int			i;

	i = -1;
	//node->cmd = cmds[0];
	//cmds++;
	argc = count_args(cmds);
	node->args = ft_calloc(argc + 1, sizeof(char *));
	while (++i < argc)
	{
		node->args[i] = cmds[0];
		cmds++;
	}
	node->args[i] = 0;
}
