/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:27:16 by becastro          #+#    #+#             */
/*   Updated: 2022/12/03 20:31:12 by umartin-         ###   ########.fr       */
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

	len = ft_doublestrlen(s1) + ft_doublestrlen(s2) + 1;
	new = ft_calloc(len, sizeof(char *));
	i = -1;
	while (++i < ft_doublestrlen(s1) && s1[i])
		new[i] = ft_strdup(s1[i]);
	j = -1;
	while (++j < ft_doublestrlen(s2) && s2[j])
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
		g_data.exit_val = WEXITSTATUS(temp_status);
	if (WIFSIGNALED(temp_status))
	{
		if (WTERMSIG(temp_status) == 2)
			g_data.exit_val = 130;
		else if ((WTERMSIG(temp_status) == 3))
			g_data.exit_val = 131;
	}
}

char	*reverse_search(const char *haystack, const char *needle)
{
	int	i;

	i = ft_strlen(haystack);
	while (i >= 0)
	{
		if (haystack[i] == needle[0]
			&& ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char *)&haystack[i]);
		i--;
	}
	return (NULL);
}

char	**str_to_double(char *str)
{
	char	**new;

	if (!str)
		return (NULL);
	new = NULL;
	new = ft_calloc(2, sizeof(char *));
	new[0] = ft_strdup(str);
	return (new);
}
