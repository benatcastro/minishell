/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:24:53 by becastro          #+#    #+#             */
/*   Updated: 2022/11/12 14:43:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		signals_core(void);
int		get_pid(void);
void	signal_reciever(int singal, siginfo_t *data, void *ucontext);

#endif
