/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 07:08:48 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include <dirent.h>

int	valid_path(char *path)
{
	DIR	*dir_ptr;
	int	rules;

	dir_ptr = opendir(path);
	rules = access(path, R_OK);
	printf("acces_test(%d)\n",)
	if (dir_ptr == NULL)
		return (0);
	printf("%p\n", dir_ptr);
	closedir(dir_ptr);
	return (1);
}

void	cd_builtin(char **args, char **env)
{
	if (ft_doublestrlen(args) == 1)
		return ;
	if (!valid_path(args[1]))
		return ((void)printf("%scd: %s: No such file or directory\n",
				PROMPT, args[1]));
}
