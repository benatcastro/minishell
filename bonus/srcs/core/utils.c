/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:27:16 by becastro          #+#    #+#             */
/*   Updated: 2022/12/02 19:42:06 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

char	**ft_doublestrjoin(char **s1, char **s2)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	len = ft_doublestrlen(s1) + ft_doublestrlen(s2);
	new = ft_calloc(len, sizeof(char *));
	i = -1;
	while (++i < ft_doublestrlen(s1) - 1)
		new[i] = ft_strdup(s1[i]);
	j = -1;
	while (++j < ft_doublestrlen(s2))
		new[i + j] = ft_strdup(s2[j]);
	return (new);
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
	if (WIFSIGNALED(temp_status))
		g_data.exit_val = 130;
}
