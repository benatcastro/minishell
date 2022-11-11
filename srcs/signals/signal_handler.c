/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/11 18:08:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"
#include <signal.h>


void	signal_reciever(int signal, siginfo_t *data, void *pid_ptr)
{
	extern t_data	*g_data;

	if (signal == SIGINT && g_data->ms_pid == g_data->sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGINT)
		printf("\n");
	if (signal == SIGQUIT)
		printf("SIGNAL = sigquit\n");
}
