/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:07:41 by bena              #+#    #+#             */
/*   Updated: 2022/09/24 14:26:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# define WHITESPACE "\20\t\f\r\n\v" //should we use "\n as white space??"
# define AMPERSAND "<AMPERSAND>"
# define PIPE "<PIPE>"
# define SEMICOLON "<SEMICOLON>"
# define GREATER "<GREATER>"
# define LESS "<LESS"

int	lexer_core(char	*cmd);

#endif
