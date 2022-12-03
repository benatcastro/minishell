/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:37:29 by bena              #+#    #+#             */
/*   Updated: 2022/12/03 17:21:00 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H
# include <unistd.h>
# include <dirent.h>

typedef struct s_values
{
	int		start;
	int		end;
	int		i;
	int		matches;
	char	*file;
	char	**split_arg;
}	t_values;

char	**add_str(char **src, char *arg);
char	**wildcard_arg_manager(char **args);
char	*wildcard_parser(char *file, char *arg);
char	*arg_is_wildcard(char **args);
char	**wildcard_core(char *arg);
char	*get_dir_files(DIR *dir_ptr, struct dirent *s_dir);
void	create_dfiles(char *path, char **dfiles);
int		get_dir_size(char *path);
#endif
