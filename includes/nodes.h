/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:45 by bena              #+#    #+#             */
/*   Updated: 2022/09/30 14:02:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H
# include "executor.h"

t_command		*ft_cmdlast(t_command *lst);
t_command_table	*ft_tablelast(t_command_table *lst);
//=================================================//

void			ft_cmdadd_back(t_command **lst, t_command *new);
void			ft_tableadd_back(t_command_table **lst, t_command_table *new);
#endif
