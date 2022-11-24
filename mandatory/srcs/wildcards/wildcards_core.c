/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/11/24 15:02:41 by umartin-         ###   ########.fr       */
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

char	*parse_wildcards(char **dfiles, char *arg)
{
	(void)dfiles;
	(void)arg;
	return (NULL);
}

char	**wildcard_core(char **args)
{
	char	*wildcard_arg;
	char	*pwd;
	char	**dfiles;

	wildcard_arg = arg_is_wildcard(args);
	if (!wildcard_arg)
		return (NULL);
	pwd = getcwd(NULL, 0);
	dfiles = ft_calloc(get_dir_size(pwd) + 1, sizeof(char *));
	create_dfiles(pwd, dfiles);
	wildcard_arg = parse_wildcards(dfiles, wildcard_arg);
	args = dfiles;
	free(pwd);
	//ft_doubleprint(dfiles);
	return (dfiles);
}
