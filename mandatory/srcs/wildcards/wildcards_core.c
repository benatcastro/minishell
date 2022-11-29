/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:46 by bena              #+#    #+#             */
/*   Updated: 2022/11/29 16:00:04 by becastro         ###   ########.fr       */
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
	int		i;
	(void)args;
	// if (&arg_is_wildcard == NULL)
		// return (NULL);
	pwd = getcwd(NULL, 0);
	dfiles = ft_calloc(get_dir_size(pwd) + 1, sizeof(char *));
	create_dfiles(pwd, dfiles);
	i = -1;
	while (dfiles[++i])
		wildcard_parser(dfiles[i], args[0]);
	free(pwd);
	return (dfiles);
}
