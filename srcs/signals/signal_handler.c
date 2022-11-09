/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 19:14:38 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>
#include "minishell.h"
#include <signal.h>

void	signal_reciever(int signal, siginfo_t *data, void *pid_ptr)
{
	// printf ("pid (%d)\n", data->si_pid);
	// if (signal == SIGINT)
		// printf("\n%s", PROMPT);
	if (signal == SIGQUIT)
		exit(EXIT_SUCCESS);
}
