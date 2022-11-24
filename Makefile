NAME = minishell
BONUS = full_minishell

RM = rm -f
ARRC = ar rc

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

INCLUDES = -I mandatory/includes/
INCLUDES_BONUS = -I bonus/includes/
CC = gcc
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
RD_FLAGS = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib/
FLAGS = -Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include -g3 -fsanitize=address

all: $(NAME)

bonus: $(BONUS)

m: $(NAME)

$(NAME):
	@echo "$(WHT)Compiling 42lib...$(EOC)"
	make -C mandatory/42lib/
	make -C mandatory/

$(BONUS):
	@echo "$(WHT)Compiling 42lib...$(EOC)"
	make -C bonus/42lib/
	make -C bonus/

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)clean done.$(EOC)"

fclean: clean
	make fclean -C mandatory/42lib/
	# make fclean -C bonus/42lib/
	# make clean -C bonus/
	make clean -C mandatory/
	@echo "$(WHT)Removing binary -files...$(EOC)"
	$(RM) $(NAME) $(BONUS)
	@echo "$(GREEN)fclean done.$(EOC)"

mrun: all
	./$(NAME)

brun: bonus
	./$(BONUS)

valgrind: all
	$(VALGRIND) ./$(NAME)

re: fclean all

.PHONY: clean re fclean all m
