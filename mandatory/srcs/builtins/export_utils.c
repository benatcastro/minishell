/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:34:50 by umartin-          #+#    #+#             */
/*   Updated: 2022/11/29 21:29:02 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"
#include "builtins.h"

void	export_temp(char **temp, char *str)
{
	char	*t1;
	char	*t2;
	int		i;
	int		c;

	t1 = ft_calloc(num_until_equal(str) + 1, sizeof(char *));
	t2 = ft_calloc((ft_strlen(str) - num_until_equal(str)), sizeof(char *));
	i = -1;
	while (++i < num_until_equal(str))
		t1[i] = str[i];
	c = 0;
	i = (num_until_equal(str));
	while (++i <= (int)ft_strlen(str))
		t2[c++] = str[i];
	temp[0] = t1;
	temp[1] = t2;
}

void	ft_export_arg(char **args)
{
	int		i;
	char	**temp;

	i = 0;
	while (args[++i])
	{
		if (export_arg_chkr(args[i]) == -1)
			return ;
		else if (export_arg_chkr(args[i]) == 0)
		{
			if (find_in_env(args[i]) == NULL)
				ft_doublestradd(args[i]);
		}
		else if (export_arg_chkr(args[i]) > 0)
		{
			temp = ft_calloc(3, sizeof(char *));
			export_temp(temp, args[i]);
			if (find_in_env(temp[0]) != NULL)
				rebuild_env(temp[0]);
			ft_doublestradd(args[i]);
		}
//		ft_doublefree(temp);
	}
}

void	ft_doubleprint_err(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (str[i])
	{
		write (2, str[i], ft_strlen(str[i]));
		write (2, "\n", 1);
		i++;
	}
}
