/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:48:45 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 05:51:03 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_echo(char **cont)
{
	int	i;

	if (!cont[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strncmp(cont[1], "-n", 3))
	{
		i = 1;
		while (cont[++i])
			printf("%s ", cont[i]);
	}
	else
	{
		i = 0;
		while (cont[++i])
			printf("%s ", cont[i]);
		printf("\n");
	}
}
