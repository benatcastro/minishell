/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 14:49:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"

void	signal_reciever(int signal, siginfo_t *data, void *ucontext)
{
	extern t_data	g_data;

	// printf("ms pid %d handle %d", g_data.ms_pid, data->si_pid);
	if (signal == SIGINT && !g_data.sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signal == SIGINT && g_data.sub_pid)
	{
		printf("\n");
		rl_on_new_line();
	}
}
