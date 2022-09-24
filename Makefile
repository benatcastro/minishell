# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bena <bena@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:25:12 by umartin-          #+#    #+#              #
#    Updated: 2022/09/24 11:45:43 by bena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#############NAMES###########
NAME = minishell
##########DIRECTORIES########
SRC_DIR = srcs/
OBJ_DIR = objs/
MINISHELL_SRCS = $(SRC_DIR)$(NAME)/
INC_DIR = includes/
LIB_DIR = libraries/

############SRCS##############
SRC =	ms_main.c \

###########OBJS##############
OBJS = $(SRC:.c=.o)

#############UTILS###########
CC = gcc
RM = rm -rf
42Lib = make -C srcs/
#############FLAGS###########
RD_FLAGS	= -I/Users/$(USER)/.brew/opt/readline/include -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
SANITIZE	= -fsanitize=address -g3
VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
CFLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address
INC_FLAGS	= -I $(INC_DIR)
LIB_FLAGS	= $(LIB_DIR)42lib.a

all: $(NAME)


%.o: %.c
	 -c $^ -o $@

$(NAME): $(OSRC)
	make -C 42lib/ --silent
	@echo "\033[33mCompiling libft...\033[0m"
	@echo "\033[33mCompiling minishell project...\033[0m"
	@$(CC) $(CFLAGS) $(MINISHELL_SRCS)$(SRC) $(RD_FLAGS) $(INC_FLAGS) $(LIB_FLAGS) $^ -o $(NAME)
	@echo "\033[92mminishell has been successfully compiled!\033[0m"

42lib:
	make -C 42lib/

clean:
	@make clean -C 42lib/
	@$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C 42lib/
	@$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re
