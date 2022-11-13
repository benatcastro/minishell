/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:15:31 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 16:39:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int	exit_builtin(void)
{
	if (!g_data.sub_pid)
	{
		printf("exit");
	}
	exit(0);
	return (0);
}
