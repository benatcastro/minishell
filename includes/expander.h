/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:34:14 by becastro          #+#    #+#             */
/*   Updated: 2022/09/30 18:52:59 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include <unistd.h>

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

char	*expander_core(char **cmds, char **env);
char	*expander_main(char	*str, char **env);
char	**expand_splitter(char *str);
int		expand_arg_num(char *str);
void	expand_arg_num_ut(char *str, int *i, int *n);
void	exander_dollar_find(char *str, char **temp, int *i, int *n);
void	expaner_no_dollar(char *str, char **temp, int *i, int *n);
char	*expander(char	*str, char **env);
char	*env_replacer(char *str, char **env);
int		num_until_equal(char *str);
char	*expand_trimmer(char	*str);
char	**double_dollar(char **cmds);

#endif
