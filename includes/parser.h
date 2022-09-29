/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:48 by umartin-          #+#    #+#             */
/*   Updated: 2022/09/29 11:19:20 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char	**parser_core(char **str);
char	*parser_quotes(char *str);
int		parser_arg_num(char *str);
int		parser_quote_error_chk(char *str);

#endif