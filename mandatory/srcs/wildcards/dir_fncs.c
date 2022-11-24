/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_fncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:20:48 by bena              #+#    #+#             */
/*   Updated: 2022/11/24 17:02:35 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dirent.h"
#include "minishell.h"
#include "wildcards.h"

void	create_dfiles(char *path, char **dfiles)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	int				index;
	char			*temp;

	index = 0;
	s_dir = NULL;
	dir_ptr = opendir(path);
	while (true)
	{
		temp = ft_strdup(get_dir_files(dir_ptr, s_dir));
		if (temp == NULL)
			break ;
		if (temp[0] != '.')
		{
			dfiles[index] = temp;
			index++;
		}
	}
	dfiles[index] = NULL;
	closedir(dir_ptr);
}

int	get_dir_size(char *path)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	int				sz;

	s_dir = NULL;
	dir_ptr = opendir(path);
	sz = 0;
	while (s_dir != NULL)
	{
		s_dir = readdir(dir_ptr);
		if (s_dir && s_dir->d_name[0] != '.')
			sz++;
	}
	closedir(dir_ptr);
	return (sz);
}

char	*get_dir_files(DIR *dir_ptr, struct dirent *s_dir)
{
	s_dir = readdir(dir_ptr);
	if (s_dir != NULL)
		return (s_dir->d_name);
	return (NULL);
}
