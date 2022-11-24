/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:15:31 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 01:47:51 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"
#include "../includes/minishell.h"

int	exit_builtin(char **str)
{
	if (str[1] == NULL)
	{
		ft_doublefree(g_data.env);
		printf("exit\n");
		exit(0);
		return (0);
	}
}
