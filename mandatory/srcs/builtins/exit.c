/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:15:31 by becastro          #+#    #+#             */
/*   Updated: 2022/11/22 15:01:07 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int	exit_builtin(void)
{
	ft_doublefree(g_data.env);
	printf("exit\n");
	exit(0);
	return (0);
}
