/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:27:16 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 08:30:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("str[%d] == %s\n", i, str[i]);
}