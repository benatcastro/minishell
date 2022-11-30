/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/11/30 15:17:20 by becastro         ###   ########.fr       */
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

	//fprintf(stderr, "ADD STR ARG: %s\n", arg);
	if (!arg)
		return (NULL);
	i = -1;
	if (src == NULL)
	{
		//fprintf(stderr, "CASE 1\n");
		new = ft_calloc(2, sizeof(char *));
		new[0] = ft_strdup(arg);
		//ft_doubleprint(new);
		return (new);
	}
	else
	{
		//fprintf(stderr, "CASE 2\n");
		new = ft_calloc(ft_doublestrlen(src) + 2, sizeof(char *));
		while (src[++i])
			new[i] = ft_strdup(src[i]);
		new[i] = ft_strdup(arg);
		//ft_doubleprint(new);
		return (new);
	}
	return (NULL);
}

// static void	remove_wildcard_from_args(char **args)
// {
// 	int		i;
// 	char	**new_args;

// 	if (ft_doublestrlen(args) == 1)
// 	{
// 		ft_doublefree(args);
// 		args = NULL;
// 		return ;
// 	}
// 	new_args = ft_calloc(ft_doublestrlen(args) - 1, sizeof(char *));
// 	i = -1;
// 	while (args[++i])
// 	{
// 		if (!ft_chr_in_set('*', args[i]))
// 			new_args[i] = ft_strdup(args[i]);
// 	}
// 	ft_doublefree(args);
// 	args = new_args;
// }

/*static char	**rebuild_args(char **args, char **dfiles)
{
	char	**new_args;
	int		i;
	int		len;

	i = -1;
	len = ft_doublestrlen(dfiles); //+ ft_doublestrlen(dfiles);
	new_args = ft_calloc(len, sizeof(char *));
	while (++i < len)
		new_args[i] = ft_strdup(dfiles[i]);
	// ft_doublefree(args);
	ft_doublefree(dfiles);
	ft_doubleprint(new_args);
	args = new_args;
	return (new_args);

}*/

char	**wildcard_core(char **args)
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
		// fprintf(stderr, "Parsed file: %s\n", wildcard_parser(dfiles[i], args[0]));
		if (wildcard_parser(dfiles[i], args[0]))
		{
			// ft_doublefree(parsed_files);
			parsed_files = add_str(parsed_files, dfiles[i]);
		}
	}
	//fprintf(stderr, "WD CORE PARSED FILES:\n");
	// ft_doubleprint(parsed_files);
	free(pwd);
	if (!parsed_files && ft_chr_in_set('*', args[0]))
		return (dfiles);
	if (!parsed_files)
		return (args);
	return (parsed_files);
}
