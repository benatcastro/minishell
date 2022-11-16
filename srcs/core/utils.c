/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:27:16 by becastro          #+#    #+#             */
/*   Updated: 2022/11/16 19:03:59 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_dupper(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		i++;
		printf("%d", i);
	}
}

void	print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("str[%d] == %s\n", i, str[i]);
}

void	get_exit_status(void)
{
	int	temp_status;

	temp_status = g_data.exit_val;
	if (WIFEXITED(temp_status))
		g_data.exit_val = (WEXITSTATUS(temp_status));
}
