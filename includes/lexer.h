/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:51:37 by becastro          #+#    #+#             */
/*   Updated: 2022/10/05 21:17:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdbool.h>

char	**lexer_core(char	*cmd);
int		check_quotes(char *str);
char	*replace_quoted_strings(char *str);
void	replace_for_spaces(char **str);
bool	ft_is_quoted(const char *ref, unsigned int index);
void	quote_logic(char *str);

#endif
