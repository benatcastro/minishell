/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/11/15 20:17:44 by becastro         ###   ########.fr       */
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

	if (ft_strcmp(path, "-") && !find_in_env("OLDPWD"))
		return (printf("%scd: OLDPWD not set\n", PROMPT), 0);
	else if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	val = valid_path(path);
	if (val == 0)
		return ((printf("%scd: %s: No such file or directory\n",
					PROMPT, path)), 0);
	else if (val == -1)
		return ((printf("%scd: %s: Permission denied\n",
					PROMPT, path)), 0);
	return (1);
}

void	update_env(char *old_cwd)
{
	char	**temp;
	char	new_cwd[256];

	temp = ft_calloc(3, sizeof(char *));
	if (!find_in_env("OLDPWD"))
	{
		temp[0] = ft_strdup("export");
		temp[1] = ft_strdup(ft_strjoin("OLD", find_in_env("PWD")));
		temp[2] = NULL;
		ft_export_arg(temp);
	}
	rebuild_env("OLDPWD");
	temp[0] = ft_strdup("export");
	temp[1] = ft_strdup(ft_strjoin("OLDPWD=", old_cwd));
	temp[2] = NULL;
	ft_export_arg(temp);
	rebuild_env("PWD");
	temp[0] = ft_strdup("export");
	getcwd(new_cwd, sizeof(new_cwd));
	temp[1] = ft_strdup(ft_strjoin("PWD=", new_cwd));
	temp[2] = NULL;
	ft_export_arg(temp);
}

void	cd_builtin(char **args)
{
	char	*path;
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	path = args[1];
	if (ft_doublestrlen(args) == 1 && find_in_env("HOME"))
		path = find_in_env("HOME") + 5;
	if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	if (path[0] == '~')
		path = ft_strjoin((find_in_env("HOME")) + 5, ++path);
	if (path == NULL || !check_dir(path))
	{
		g_data.exit_val = 1;
		return ;
	}
	if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	chdir(path);
	update_env(cwd);
}
