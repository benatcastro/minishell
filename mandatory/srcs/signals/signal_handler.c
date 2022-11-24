/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/23 19:00:29 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/signals.h"
#include <stdio.h>
#include "../includes/minishell.h"

void	signal_reciever(int signal, siginfo_t *data, void *ucontext)
{
	(void)data;
	(void)ucontext;
	if (signal == SIGINT && !g_data.sub_pid)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if ((signal == SIGINT || signal == SIGQUIT) && g_data.sub_pid)
	{
		g_data.exit_val = 130;
		g_data.sub_pid = 0;
		printf("\r");
		printf("\n");
		rl_on_new_line();
	}
}
