/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/09/29 14:04:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"

static bool	ft_is_expand(char **cmds)
{
	print_double_str(cmds);
	return (false);
}

int	expander_core(char **cmds)
{
	ft_is_expand(cmds);
	return (0);
}
