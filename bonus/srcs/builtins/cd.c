/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/12/10 15:45:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include <dirent.h>

extern t_data	g_data;

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
		return (printerr("%scd: OLDPWD not set\n", PROMPT_ERR), 0);
	else if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	val = valid_path(path);
	if (val == 0)
		return ((printerr("%scd: %s: No such file or directory\n",
					PROMPT_ERR, path)), 0);
	else if (val == -1)
		return ((printerr("%scd: %s: Permission denied\n",
					PROMPT_ERR, path)), 0);
	return (1);
}

void	update_env(char *old_cwd)
{
	char	**temp;
	char	*new_cwd;

	if (!find_in_env("OLDPWD"))
	{
		temp = ft_calloc(3, sizeof(char *));
		temp[0] = ft_strdup("export");
		temp[1] = ft_strjoin("OLD", find_in_env("PWD"));
		ft_export_arg(temp);
		ft_doublefree(temp);
	}
	rebuild_env("OLDPWD");
	temp = ft_calloc(3, sizeof(char *));
	temp[0] = ft_strdup("export");
	temp[1] = ft_strjoin("OLDPWD=", old_cwd);
	ft_export_arg(temp);
	ft_doublefree(temp);
	rebuild_env("PWD");
	new_cwd = getcwd(NULL, 0);
	temp = ft_calloc(3, sizeof(char *));
	temp[0] = ft_strdup("export");
	temp[1] = ft_strjoin("PWD=", new_cwd);
	ft_export_arg(temp);
	ft_doublefree(temp);
	free(new_cwd);
}

void	cd_builtin(char **args)
{
	char	*path;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	path = args[1];
	if (ft_doublestrlen(args) == 1 && find_in_env("HOME"))
		path = find_in_env("HOME") + 5;
	else if (!path)
		return (free(cwd), (void)printerr("%scd: HOME not set\n", PROMPT_ERR));
	if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	if (path[0] == '~')
		path = ft_strjoin((find_in_env("HOME")) + 5, ++path);
	if (path == NULL || !check_dir(path))
	{
		g_data.exit_val = 1;
		return (free(cwd));
	}
	if (ft_strcmp(path, "-") && find_in_env("OLDPWD"))
		path = find_in_env("OLDPWD") + 7;
	chdir(path);
	update_env(cwd);
	free(cwd);
}
