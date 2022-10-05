/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:37 by becastro          #+#    #+#             */
/*   Updated: 2022/10/05 13:35:46 by becastro         ###   ########.fr       */
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
	printf("=====THIS IS A TEST=====\n");
	print_double_str(args);
	while (args[++i])
	{
		if (args[i][0] == '-')
			argc++;
		else
			break ;
	}
	return (argc);
}

void	fill_cmd(t_command *node, char **cmds)
{
	size_t		argc;
	static char	**s_cmds;
	static bool	check;
	int			i;

	if (!check)
	{
		s_cmds = ft_doublestrdup(cmds);
		check = true;
	}
	i = -1;
	node->cmd = s_cmds[0];
	s_cmds++;
	argc = count_args(s_cmds);
	node->args = ft_calloc(argc + 1, sizeof(char *));
	while (++i < argc)
	{
		node->args[i] = s_cmds[0];
		s_cmds++;
	}
	node->args[i] = '\0';
	node->cmd_input = s_cmds[0];
}
