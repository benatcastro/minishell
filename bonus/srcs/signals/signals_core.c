/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:20 by becastro          #+#    #+#             */
/*   Updated: 2022/11/18 18:42:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "minishell.h"

int	get_pid(void)
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

	sig_data.sa_sigaction = signal_reciever;
	sigemptyset (&sig_data.sa_mask);
	sig_data.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sig_data, NULL);
	sigaction(SIGQUIT, &sig_data, NULL);
	return (1);
}
