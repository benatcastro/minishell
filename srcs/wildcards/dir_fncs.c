/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_fncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:20:48 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 23:29:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dirent.h"
#include "minishell.h"

size_t	get_dir_size(char *path)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	size_t			size;

	size = 0;
	dir_ptr = opendir(path);
	while (s_dir)
	{
		s_dir = readdir(dir_ptr);
		if (s_dir->d_name[0] != '.')
			size++;
	}
	return (closedir(dir_ptr), size);
}

char	**get_dir_files(char *path)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	char			**files;
	int				index;

	files = ft_calloc(1, (get_dir_size(path) + 1) * sizeof(char *));
	index = -1;
	dir_ptr = opendir(path);
	while (s_dir)
	{
		s_dir = readdir(dir_ptr);
		if (s_dir->d_name[0] != '.')
			files[++index] = ft_strdup(s_dir->d_name);
	}
	files[index] = NULL;
	closedir(dir_ptr);
}
