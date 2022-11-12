/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 14:14:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"

void	signal_reciever(int signal)
{
	extern t_data	g_data;

	if (signal == SIGINT && !g_data.sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		g_data.sub_pid = 0;
	}
	else if (signal == SIGINT && g_data.sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		g_data.sub_pid = 0;
	}
}
