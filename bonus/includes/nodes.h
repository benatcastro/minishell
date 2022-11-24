/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:45 by bena              #+#    #+#             */
/*   Updated: 2022/11/24 00:25:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H
# include "executor.h"

t_command		*ft_cmdlast(t_command *lst);
t_command_table	*ft_tablelast(t_command_table *lst);
t_redir			*ft_redirlast(t_redir *lst);
//=================================================//

void			ft_cmdadd_back(t_command **lst, t_command *new);
void			ft_tableadd_back(t_command_table **lst, t_command_table *new);
void			ft_rediradd_back(t_redir **lst, t_redir *new);
void			print_table(t_command_table **table_head);
t_command_table	*create_command_table_node(char **cmds, short _separator);
t_command_table	**create_command_table(t_command_table **head, char **cmds);
t_command		*create_cmd_node(char **cmds);
t_command		**create_cmd(t_command **cmd_head, char **cmds);
t_redir			*create_redir_node(char **content);

//======================FREE FNCS=================//
void			free_command_table_nodes(t_command_table **head);
#endif
