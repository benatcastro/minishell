/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:20 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 14:05:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "minishell.h"
#include <termios.h>

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

void	sigquit_replacer(void)
{
	struct termios	pre_term;
	struct termios	term;

	tcgetattr(0, &pre_term);
	term = pre_term;
	term.c_cc[VEOF] = 3;
	term.c_cc[VINTR] = 4;
	tcsetattr(0, TCSANOW, &term);
	tcsetattr(0, TCSANOW, &pre_term);
}

int	signals_core(void)
{
	signal(SIGINT, signal_reciever);
	return (0);
}
