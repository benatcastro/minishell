/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/11/08 15:45:53by bena             ###   ########.fr       */
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

void	parse_wildcards(char **dfiles, char *arg)
{
	char	**parsing;
	int		i;
	int		j;

	parsing = ft_split(arg, '*');
	if (!parsing[0])
		return ;
	printf("WD arg: %s\n", arg);
	fprintf(stderr, "parsing\n");
	print_double_str(parsing);
	i = -1;
	chdir("srcs/");
	while (dfiles[++i])
	{
		j = -1;
		while (parsing[++j])
		{
			while (ft_strchr(dfiles[i], parsing[j][0])
				|| ft_strnstr(dfiles[i], parsing[j], ft_strlen(parsing[j])))
			{
				dfiles[i] = ft_strchr(dfiles[i], parsing[j][0]);
				if (dfiles[i])
					fprintf(stderr, "Parse: %s\n", dfiles[i]);
			}
		}
	}
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
	parse_wildcards(dfiles, wildcard_arg);
	args = dfiles;
	free(pwd);
	//ft_doubleprint(dfiles);
	return (dfiles);
}
