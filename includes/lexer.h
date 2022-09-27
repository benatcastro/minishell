/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:51:37 by becastro          #+#    #+#             */
/*   Updated: 2022/09/27 16:56:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdbool.h>

# define WHITESPACE " \t\f\r\n\v" //should we use "\n as white space??"
# define REPLACE_CHAR 26

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

# define AMPERSAND "<AMPERSAND>"
# define DOUBLEAMPERSAND "DOUBLEAMPERSAND"

# define PIPE "<PIPE>"
# define DOUBLEPIPE "<DOUBLEPIPE>"

# define GREATER "<GREATER>"
# define DOUBLEGREATER "<DOUBLEGREATER>"

# define LESS "<LESS>"
# define DOUBLELESS "<DOUBLELESS>"

# define SEMICOLON "<SEMICOLON>"

char	**lexer_core(char	*cmd);
int		check_quotes(char *str);
char	*replace_quoted_strings(char *str);
void	replace_for_spaces(char **str);
bool	ft_is_quoted(const char *ref, unsigned int index);
void	quote_logic(char *str);

#endif
