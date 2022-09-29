/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:34:14 by becastro          #+#    #+#             */
/*   Updated: 2022/09/29 14:03:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include <unistd.h>

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

int	expander_core(char **cmds);

#endif
