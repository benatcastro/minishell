/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 12:02:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include <dirent.h>

int	valid_path(char *path)
{
	int	exists;
	int	permission;

	permission = access(path, R_OK);
	exists = access(path, F_OK);
	if (exists == -1)
		return (0);
	if (permission == -1)
		return (-1);
	return (1);
}

static int	check_dir(char *path)
{
	int	val;

	val = valid_path(path);
	if (ft_strcmp(path, "-") && !find_in_env(path))
		return (printf("%scd: OLDPWD not set\n", PROMPT), 0);
	if (val == 0)
		return ((printf("%scd: %s: No such file or directory\n",
					PROMPT, path)), 0);
	else if (val == -1)
		return ((printf("%scd: %s: Permission denied\n",
					PROMPT, path)), 0);
	return (1);
}

void	cd_builtin(char **args)
{
	char	*path;

	path = args[1];
	if (path == NULL || !check_dir(path))
		return ;
	chdir(path);
}
