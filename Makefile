# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becastro <becastro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:25:12 by umartin-          #+#    #+#              #
#    Updated: 2022/10/05 09:44:03 by becastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#############NAMES###########
NAME = minishell
##########DIRECTORIES########
SRC_DIR = srcs/
OBJ_DIR = objs/$(NAME)/
INC_DIR = includes/
LIB_DIR = libraries/

#############UTILS###########
CC = gcc
RM = rm -rf
42Lib = make -C srcs/
#############FLAGS###########
RD_FLAGS	= -I/Users/$(USER)/.brew/opt/readline/include -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
SANITIZE	= -fsanitize=address -g3
VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
CFLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3
INC_FLAGS	= -I $(INC_DIR)
LIB_FLAGS	= $(LIB_DIR)42lib.a

#############NAMES###########
RAW_OBJS =	ms_main			\
			lexer_core		\
			replace_quotes	\
			signals_core	\
			signal_handler	\
			parser_core		\
			parser_errors	\
			parser_utils	\
			expander_core	\
			expander_utils	\

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW_OBJS)))



all: $(NAME)

$(NAME): $(OBJS)

	@echo "\033[33mCompiling minishell project...\033[0m"
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o $(RD_FLAGS) $(INC_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@echo "\033[92mminishell has been successfully compiled!\033[0m"

$(OBJS):
	mkdir -p objs/minishell/
	echo "\033[33mCompiling 42lib...\033[0m"
	make -C 42lib/
	echo "\033[33mCompiling minishell objects...\033[0m"
	mkdir -p objs/minishell/
	make -C srcs/core
	make -C srcs/lexer
	make -C srcs/parser
	make -C srcs/signals
	make -C srcs/expander
	make -C srcs/executor

run: all
	./$(NAME)

clean:
	@$(RM) objs/

fclean: clean
	make fclean -C 42lib/
	$(RM) $(NAME)
re: fclean all

.PHONY: all foo clean fclean re
