/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:20 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 19:03:53 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "minishell.h"

int	real_pid(void)
{
	int		s;
	int		pid;

	pid = fork();
	if (pid == 0)
		exit (0);
	else
		s = pid;
	return (s - 1);
}

int	signals_core(void)
{
	struct sigaction	sig_data;
	struct sigaction	pid;

	sig_data.sa_sigaction = signal_reciever;
	sigemptyset (&sig_data.sa_flags);
	sig_data.sa_mask = SA_SIGINFO;
	sigaction(SIGINT, &sig_data, &pid);
	sigaction(SIGQUIT, &sig_data, &pid);
	return (pid.sa_flags);
}
