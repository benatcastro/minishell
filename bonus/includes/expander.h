/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:34:14 by becastro          #+#    #+#             */
/*   Updated: 2022/11/14 15:28:37 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include <unistd.h>

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

char	*expander_core(char **cmds);
char	*expander_main(char	*str);
char	**expand_splitter(char *str, char **rtn);
int		expand_arg_num(char *str);
void	expand_arg_num_ut(char *str, int *i, int *n);
void	exander_dollar_find(char *str, char **temp, int *i, int *n);
void	expaner_no_dollar(char *str, char **temp, int *i, int *n);
char	*expand_first_trimmer(char	*str);
char	**expander(char	*str);
int		num_until_equal(char *str);
char	*expand_trimmer(char	*str);
char	**double_dollar(char **cmds);
char	*double_joiner(char **temp);
char	*env_val_maker(char *val, int *n, int *i);
void	expand_arg_num_ut(char *str, int *e, int *c);
void	expand_splitter_ut(char *str, int *e);
char	*expand_splitter_ut2(char *str, char *aux, int *e, int *l);
char	*ft_strdup_free(char *s1);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
