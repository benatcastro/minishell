/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:48:45 by becastro          #+#    #+#             */
/*   Updated: 2022/11/24 16:50:33 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_echo(char **cont)
{
	int	i;

	if (!cont[1])
		return ((void)printf("\n"));
	if (!ft_strncmp(cont[1], "-n", 3))
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