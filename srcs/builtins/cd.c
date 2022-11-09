/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 07:27:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include <dirent.h>

int	valid_path(char *path)
{
	DIR	*dir_ptr;
	int	access_val;

	dir_ptr = opendir(path);
	access_val = access(path, R_OK);
	if (access_val == -1)
		return (access_val);
	if (dir_ptr == NULL)
		return (0);
	printf("%p\n", dir_ptr);
	closedir(dir_ptr);
	return (1);
}

static int	check_dir(char *path)
{
	int	val;

	val = valid_path(path);
	if (val == 0)
		return (((void)printf("%scd: %s: No such file or directory\n",
					PROMPT, path)), 0);
	else if (val == -1)
		return (((void)printf("%scd: %s: Permission denied\n",
					PROMPT, path)), 0);
	return (1);
}

void	cd_builtin(char **args, char **env)
{
	if (ft_doublestrlen(args) == 1 || check_dir(args[1]))
		return ;
}
