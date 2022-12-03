/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:48:45 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 17:32:35 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_echo(char **cont)
{
	int	i;

	if (!cont[1])
		return ((void)printf("\n"));
	if (cont[1][0] == '-' && cont[1][1] == 'n')
	{
		i = 1;
		while (cont[++i])
		{
			printf("%s", cont[i]);
			if (cont[i + 1] != NULL)
				printf(" ");
		}
	}
	else
	{
		i = 0;
		while (cont[++i])
		{
			printf("%s", cont[i]);
			if (cont[i + 1] != NULL)
				printf(" ");
		}
		printf("\n");
	}
}
