/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/12 18:58:05 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/11/12 23:56:40 by becastro         ###   ########.fr       */
>>>>>>> beta-v2
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"

void	signal_reciever(int signal, siginfo_t *data, void *ucontext)
{
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
		g_data.sub_pid = 0;
	}
}
