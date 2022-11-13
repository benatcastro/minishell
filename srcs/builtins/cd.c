/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:27:26 by becastro          #+#    #+#             */
/*   Updated: 2022/11/13 00:42:45 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include <dirent.h>

static int	valid_path(char *path)
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
	if (val == 0)
		return ((printf("%scd: %s: No such file or directory\n",
					PROMPT, path)), 0);
	else if (val == -1)
		return ((printf("%scd: %s: Permission denied\n",
					PROMPT, path)), 0);
	return (1);
}

static void	change_path(char *path, char **env)
{
	char	*oldpwd;
	char	*pwd;
	int		i;

	i = -1;
	fprintf(stderr, "change path fnc start\n");
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD", ft_strlen("OLDPWD")))
			fprintf(stderr, "test %s\n", env[i]);
	}
}

void	cd_builtin(char **args, char **env)
{
	int		i;
	int		j;

	//if (ft_doublestrlen(args) == 1 || check_dir(args[1] != 1))
		//return ;
	change_path(args[1], env);
}
