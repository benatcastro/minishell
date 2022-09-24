/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:07:41 by bena              #+#    #+#             */
/*   Updated: 2022/09/24 18:20:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# define WHITESPACE " \t\f\r\n\v" //should we use "\n as white space??"

# define AMPERSAND "<AMPERSAND>"
# define DOUBLEAMPERSAND "DOUBLEAMPERSAND"

# define PIPE "<PIPE>"
# define DOUBLEPIPE "<DOUBLEPIPE>"

# define GREATER "<GREATER>"
# define DOUBLEGREATER "<DOUBLEGREATER>"

# define LESS "<LESS>"
# define DOUBLELESS "<DOUBLELESS>"

# define SEMICOLON "<SEMICOLON>"

int	lexer_core(char	*cmd);

#endif
