/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:59:56 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/30 17:00:11 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

int	env_printable(char *arg)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while (arg[++i])
		if (arg[i] == '=')
			cont++;
	if (cont == 0)
		return (-1);
	else
		return (1);
}

void	env_printer(void)
{
	int		i;

	i = -1;
	while (g_data.env[++i])
		if (env_printable(g_data.env[i]) == 1)
			printf("%s\n", g_data.env[i]);
}
