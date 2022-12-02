/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:37:29 by bena              #+#    #+#             */
/*   Updated: 2022/12/02 21:56:08 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H
# include <unistd.h>
# include <dirent.h>

char	*wildcard_parser(char *file, char *arg);
char	*arg_is_wildcard(char **args);
char	**wildcard_core(char *arg);
char	*get_dir_files(DIR *dir_ptr, struct dirent *s_dir);
void	create_dfiles(char *path, char **dfiles);
int		get_dir_size(char *path);
#endif
