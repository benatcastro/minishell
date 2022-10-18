/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:22 by becastro          #+#    #+#             */
/*   Updated: 2022/10/13 16:51:32 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdio.h>

void	signal_reciever(int signal, siginfo_t *data, void *ucontext)
{
	(void)ucontext;
	(void)data;
	printf("recieved signal (%d)\n", signal);
}
