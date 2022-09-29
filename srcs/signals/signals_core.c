/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:20 by becastro          #+#    #+#             */
/*   Updated: 2022/09/28 18:24:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

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