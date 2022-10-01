/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:48 by umartin-          #+#    #+#             */
/*   Updated: 2022/10/01 15:36:48 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//CORE
char	**parser_core(char **str, char **env);
char	**parser_quotes(char *str);
int		parser_arg_num(char *str);
int		parser_quote_error_chk(char *str);

//UTILS
void	parser_double_q(char *str, char **temp, int *i, int *n);
void	parser_single_q(char *str, char **temp, int *i, int *n);
void	parser_no_q(char *str, char **temp, int *i, int *n);
void	parser_arg_num_ut(char *str, int *i, int *n);
void	parser_quote_error_chk_utl_sq(char *str, int *b, int *i);
void	parser_quote_error_chk_utl_dq(char *str, int *b, int *i);

//LEXER
char	**lex_core(char *str);
char	*lex_first_spc_rm(char *str);
int		lex_memory_splitter(char *str);
char	**lex_splitter(char *str, char **temp);

#endif