NAME = ../minishell_bonus

LIBFT_PATH		=	./42lib
LIBFT			=	$(LIBFT_PATH)/42lib.a

SRC = srcs/core/ms_main.c \
srcs/core/utils.c \
srcs/core/global_error_chkcr.c \
srcs/builtins/builtins_core.c \
srcs/builtins/cd.c \
srcs/builtins/echo.c \
srcs/builtins/exit.c \
srcs/builtins/export.c \
srcs/builtins/env_utils.c \
srcs/builtins/export_utils.c \
srcs/builtins/unset.c \
srcs/expander/expander_core.c \
srcs/expander/expander_env_rep.c \
srcs/expander/expander_splitter.c \
srcs/expander/expander_utils.c \
srcs/lexer/lex_utils.c \
srcs/lexer/lex_utils2.c \
srcs/lexer/lex.c \
srcs/lexer/temp_utils.c \
srcs/executor/executor_core.c \
srcs/executor/executor_main.c \
srcs/executor/executor_utils.c \
srcs/executor/executor_utils2.c \
srcs/executor/executor_utils3.c \
srcs/executor/fill_cmd_table.c \
srcs/executor/node_manager.c \
srcs/executor/redir.c \
srcs/executor/gnl.c \
srcs/executor/redirections.c \
srcs/executor/redirection_utils.c \
srcs/executor/special_split.c \
srcs/node_fncs/free_nodes.c \
srcs/node_fncs/ft_nodelast.c \
srcs/node_fncs/ft_nodeadd_back.c \
srcs/node_fncs/node_utils.c \
srcs/parser/parser_core.c \
srcs/parser/parser_errors.c \
srcs/parser/parser_utils.c \
srcs/signals/signal_handler.c \
srcs/signals/signals_core.c \
srcs/wildcards/dir_fncs.c \
srcs/wildcards/wildcards_core.c \
srcs/wildcards/wildcards_parser.c \

OBJ = $(SRC:.c=.o)

RM = rm -f
ARRC = ar rc

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

INCLUDES = -I includes/
CC = gcc
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
RD_FLAGS = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib/
FLAGS = -Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include -g3 -fsanitize=address



all: $(NAME)

m: $(NAME)

$(NAME): $(OBJ)
	@echo "\033c"
	@echo "$(WHT)Compiling 42lib...$(EOC)"
	@echo "\n"
	make -C 42lib/
	@$(CC) $(FLAGS) $(RD_FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) libraries/42lib.a
	@echo "$(RED) ******       **      ******** **      **                **         "
	@echo "$(RED)/*////**     ****    **////// /**     /**               /**         "
	@echo "$(RED)/*   /**    **//**  /**       /**     /**  ******       /**  ****** "
	@echo "$(RED)/******    **  //** /*********/********** //////**   ****** **////**"
	@echo "$(RED)/*//// ** **********////////**/**//////**  *******  **///**/**   /**"
	@echo "$(RED)/*    /**/**//////**       /**/**     /** **////** /**  /**/**   /**"
	@echo "$(RED)/******* /**     /** ******** /**     /**//********//******//****** "
	@echo "$(RED)///////  //      // ////////  //      //  ////////  //////  //////  $(EOC)"
	@echo "\n"
	@echo "$(YEL)42 minishell with bonus :D"
	@echo "\n"
	@echo "$(WHT)minishell_bonus build completed."
	@echo "\n"

%.o: %.c
	@$(CC) $(INCLUDES) $(FLAGS) -c $^ -o $@

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	$(RM) $(OBJ)
	@echo "$(GREEN)clean done.$(EOC)"

fclean: clean
	@make fclean -C 42lib/
	@echo "$(WHT)Removing binary -files...$(EOC)"
	$(RM) $(NAME)
	@echo "$(GREEN)fclean done.$(EOC)"

run: all
	./$(NAME)

valgrind: all
	$(VALGRIND) ./$(NAME)

re: fclean all

.PHONY: clean re fclean all m
