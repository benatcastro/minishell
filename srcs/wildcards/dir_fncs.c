/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_fncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:20:48 by bena              #+#    #+#             */
/*   Updated: 2022/11/08 00:11:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dirent.h"
#include "minishell.h"

void	alloc_dir_size(char *path, char **files)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	size_t			size;

	size = 0;
	dir_ptr = opendir(path);
	while (s_dir)
	{
		s_dir = readdir(dir_ptr);
		size++;
	}
	files = ft_calloc(size, sizeof(char *));
	closedir(dir_ptr);
}

void	write_dir_files(char *path, char **files)
{
	DIR				*dir_ptr;
	struct dirent	*s_dir;
	int				index;

	index = 0;
	dir_ptr = opendir(path);
	while (s_dir)
	{
		s_dir = readdir(dir_ptr);
		printf("write_test (%s)\n", s_dir->d_name);
		files[index] = ft_strdup(s_dir->d_name);
		index++;
	}
	files[index] = NULL;
	closedir(dir_ptr);
}
