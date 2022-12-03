/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/12/03 15:59:23 by umartin-         ###   ########.fr       */
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

char	**add_str(char **src, char *arg)
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
	int		i;
	int		j;
	char	**new;
	char	**wc_split;

	new = NULL;
	i = -1;
	while (args[++i])
	{
		if (ft_chr_in_set('*', args[i]))
		{
			wc_split = wildcard_core(args[i]);
			if (!wc_split)
				continue ;
			j = -1;
			while (wc_split[++j])
				new = add_str(new, ft_strdup(wc_split[j]));
			if (wc_split)
				ft_doublefree(wc_split);
		}
		else
			new = add_str(new, args[i]);
	}
	return (new);
}

char	**wildcard_core(char *arg)
{
	char	*pwd;
	char	**dfiles;
	char	**parsed_files;
	int		i;

	parsed_files = NULL;
	pwd = getcwd(NULL, 0);
	dfiles = ft_calloc(get_dir_size(pwd) + 2, sizeof(char *));
	create_dfiles(pwd, dfiles);
	i = -1;
	while (dfiles[++i])
		if (wildcard_parser(dfiles[i], arg))
			parsed_files = add_str(parsed_files, dfiles[i]);
	free(pwd);
	if (!parsed_files && is_wildcard(arg) == 1)
		return (dfiles);
	if (!parsed_files)
	{
		parsed_files = ft_calloc(2, sizeof(char *));
		parsed_files[0] = arg;
		return (parsed_files);
	}
	return (parsed_files);
}
