/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:27:16 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 17:43:00 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

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
		g_data.exit_val = WEXITSTATUS(temp_status);
	if (WIFSIGNALED(temp_status))
	{
		if (WTERMSIG(temp_status) == 2)
			g_data.exit_val = 130;
		else if ((WTERMSIG(temp_status) == 3))
			g_data.exit_val = 131;
	}
}
