/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:51:37 by becastro          #+#    #+#             */
/*   Updated: 2022/11/09 15:14:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdbool.h>

# define WHITESPACE " \t\f\r\n\v" //should we use "\n as white space??"
# define REPLACE_CHAR 26

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

# define DOUBLEAMPERSAND "<DOUBLEAMPERSAND>"

# define PIPE "<PIPE>"
# define DOUBLEPIPE "<DOUBLEPIPE>"

# define GREATER "<GREATER>"
# define DOUBLEGREATER "<DOUBLEGREATER>"

# define LESS "<LESS>"
# define DOUBLELESS "<DOUBLELESS>"

# define SEMICOLON "<SEMICOLON>"

int		lex_memory_splitter(char *str);
char	**lex_splitter(char *str, char **temp);
char	**lex_core(char *str);
void	lex_splitter_ut(char **temp, char *str, int i[2], int *n);
void	lex_splitter_quote_ut(char *str, int *e);

#endif
