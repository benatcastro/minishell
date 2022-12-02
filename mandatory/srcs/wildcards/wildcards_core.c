/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/12/02 22:03:04 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
#include "minishell.h"
#include <dirent.h>

char	*arg_is_wildcard(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		if (ft_chr_in_set('*', args[i]))
			return (args[i]);
	return (NULL);
}

static char	**add_str(char **src, char *arg)
{
	char	**new;
	int		i;

	if (!arg)
		return (NULL);
	i = -1;
	if (src == NULL)
	{
		new = ft_calloc(2, sizeof(char *));
		new[0] = ft_strdup(arg);
		return (new);
	}
	else
	{
		new = ft_calloc(ft_doublestrlen(src) + 2, sizeof(char *));
		while (src[++i])
			new[i] = ft_strdup(src[i]);
		new[i] = ft_strdup(arg);
		return (new);
	}
	return (NULL);
}

int	is_wildcard(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != '*')
			return (0);
	return (1);
}

char	**wildcard_arg_manager(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (ft_chr_in_set('*', args[i]))

	}
}

char	**wildcard_core(char *arg)
{
	char	*pwd;
	char	**dfiles;
	char	**parsed_files;
	int		i;

	parsed_files = NULL;
	pwd = getcwd(NULL, 0);
	dfiles = ft_calloc(get_dir_size(pwd) + 1, sizeof(char *));
	create_dfiles(pwd, dfiles);
	i = -1;
	while (dfiles[++i])
	{
		if (wildcard_parser(dfiles[i], arg))
			parsed_files = add_str(parsed_files, dfiles[i]);
	}
	//fprintf(stderr, "WD CORE PARSED FILES:\n");
	// ft_doubleprint(parsed_files);
	free(pwd);
	if (!parsed_files && is_wildcard(arg) == 1)
		return (dfiles);
	if (!parsed_files)
	{
		parsed_files = ft_calloc(1, sizeof(char *));
		parsed_files[0] = arg;
		return (parsed_files);
	}
	return (parsed_files);
}
