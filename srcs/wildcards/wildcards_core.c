/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/11/08 00:10:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"
#include "minishell.h"
#include <dirent.h>

static char	*arg_is_wildcard(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		if (ft_chr_in_set('*', args[i]))
			return (args[i]);
	return (NULL);
}

void	wildcard_core(char **args, char **env)
{
	char	*wildcard_arg;
	char	*pwd;
	char	**files;

	files = ft_calloc(15, sizeof(char *));
	if (!arg_is_wildcard(args))
		return ;
	wildcard_arg = arg_is_wildcard(args);
	pwd = getcwd(NULL, 0);
	// alloc_dir_size(pwd, files);
	write_dir_files(pwd, files);
	printf("(test: %s)\n", files[1]);
	free(pwd);
}
