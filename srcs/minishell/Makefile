# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:25:12 by umartin-          #+#    #+#              #
#    Updated: 2022/09/20 17:57:52 by umartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CSRC =	ms_main.c \

OSRC = $(CSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LDFLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
CPPFLAGS= -I/Users/$(USER)/.brew/opt/readline/include
GCCCMD = gcc

LIBFT = cd../libft/libft.all

all: $(NAME)

%.o: %.c
	@$(GCCCMD) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@

$(NAME): $(OSRC)
	@echo "\033[33mCompiling libft...\033[0m"
	@make -C libft
	@make -C libft/ bonus
	@mv libft/libft.a .
	@echo "\033[33mCompiling minishell project...\033[0m"
	@$(GCCCMD) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) libft.a $^ -o $(NAME)
	@echo "\033[92mminishell has been successfully compiled!\033[0m"

clean:
	@rm -f $(OSRC)
	@rm -f libft.a
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

PHONY: all clean fclean re