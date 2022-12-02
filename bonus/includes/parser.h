/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:48 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/02 15:30:36 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//CORE
char	**parser_core(char **str);
char	**parser_quotes(char *str);
int		parser_arg_num(char *str);
int		parser_q_error_chk(char *str);
char	**parser_double_quote_free(char **str);

//UTILS
void	parser_double_q(char *str, char **temp, int *i, int *n);
void	parser_single_q(char *str, char **temp, int *i, int *n);
void	parser_no_q(char *str, char **temp, int *i, int *n);
void	parser_q_error_chk_utl_sq(char *str, int *b, int *i);
void	parser_q_error_chk_utl_dq(char *str, int *b, int *i);
void	parser_paren(char *str, char **temp, int *i, int *n);

#endif