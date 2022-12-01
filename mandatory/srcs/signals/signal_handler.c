/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/12/01 21:36:28 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"

extern t_data	g_data;

void	signal_reciever(int signal)
{
	if (signal == SIGINT && g_data.sub_pid == 0)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGINT && g_data.sub_pid == 1)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		g_data.exit_val = 130;
		g_data.sub_pid = 0;
	}
	// else if ((signal == SIGINT || signal == SIGQUIT) && g_data.sub_pid)
	// {
	// 	g_data.exit_val = 130;
	// 	g_data.sub_pid = 0;
	// 	printf("\r");
	// 	printf("\n");
	// 	rl_on_new_line();
	// }
}
