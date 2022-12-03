/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:20 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 16:18:27 by umartin-         ###   ########.fr       */
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
