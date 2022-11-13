/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 05:35:46 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"

void	signal_reciever(int signal, siginfo_t *data, void *ucontext)
{
	(void)data;
	(void)ucontext;
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
