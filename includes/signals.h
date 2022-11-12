/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:53 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 13:59:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	signal_reciever(int signal, siginfo_t *data, void *ucontext);
int		get_pid(void);

#endif
