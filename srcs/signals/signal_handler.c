/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 12:59:37 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"
#include <signal.h>


void	signal_reciever(int signal, siginfo_t *data, void *pid_ptr)
{
	extern t_data	*g_data;

	//printf("SIGNAL (%d)\n", signal);
	if (signal == SIGINT && g_data->sub_pid)
	{
		printf("TEST\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		g_data->sub_pid = 0;
	}
	else if (signal == SIGINT && !g_data->sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
		// printf("\n");
}
