BONUS = ../full_minishell

LIBFT_PATH		=	../42lib
LIBFT			=	$(LIBFT_PATH)/42lib.a

SRC_BONUS = srcs/core/ms_main.c \
srcs/core/utils.c \
srcs/builtins/builtins_core.c \
srcs/builtins/cd.c \
srcs/builtins/echo.c \
srcs/builtins/exit.c \
srcs/builtins/export.c \
srcs/builtins/export_utils.c \
srcs/builtins/unset.c \
srcs/expander/expander_core.c \
srcs/expander/expander_env_rep.c \
srcs/expander/expander_splitter.c \
srcs/expander/expander_utils.c \
srcs/lexer/lex_utils.c \
srcs/lexer/lex.c \
srcs/lexer/temp_utils.c \
srcs/executor/executor_core.c \
srcs/executor/executor_main.c \
srcs/executor/executor_utils.c \
srcs/executor/executor_utils2.c \
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

OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f
ARRC = ar rc

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

INCLUDES_BONUS = -I includes/
CC = gcc
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
RD_FLAGS = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib/
FLAGS = -Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include -g3 -fsanitize=address

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	@echo "$(WHT)Compiling 42lib...$(EOC)"
	make -C ../42lib/
	@echo ""
	@echo "$(WHT)Compiling:$(EOC)"
	@echo ""
	@echo "$(RED) ******       **      ******** **      **                **         "
	@echo "$(RED)/*////**     ****    **////// /**     /**               /**         "
	@echo "$(RED)/*   /**    **//**  /**       /**     /**  ******       /**  ****** "
	@echo "$(RED)/******    **  //** /*********/********** //////**   ****** **////**"
	@echo "$(RED)/*//// ** **********////////**/**//////**  *******  **///**/**   /**"
	@echo "$(RED)/*    /**/**//////**       /**/**     /** **////** /**  /**/**   /**"
	@echo "$(RED)/******* /**     /** ******** /**     /**//********//******//****** "
	@echo "$(RED)///////  //      // ////////  //      //  ////////  //////  //////  $(EOC)"
	@echo ""
	@echo "$(YEL)Full 42 minishell with bonus :D $(EOC)"
	@echo ""
	@echo ""
	@$(CC) $(FLAGS) $(RD_FLAGS) $(INCLUDES_BONUS) -o $(BONUS) $(OBJ_BONUS) ../libraries/42lib.a

%.o: %.c
	@$(CC) $(INCLUDES_BONUS) $(FLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJ_BONUS) $(BONUS)

run: bonus
	./$(BONUS)

re: fclean all

.PHONY: clean re fclean bonus