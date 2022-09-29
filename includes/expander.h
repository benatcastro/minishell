/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:34:14 by becastro          #+#    #+#             */
/*   Updated: 2022/09/29 20:21:08 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include <unistd.h>

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

char	*expander_core(char **cmds);
char	*expander_main(char	*str);
char	*expand_splitter(char *str);
int		expand_arg_num(char *str);
void	expand_arg_num_ut(char *str, int *i, int *n);

#endif
