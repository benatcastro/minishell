NAME = minishell

LIBFT_PATH		=	./42lib
LIBFT			=	$(LIBFT_PATH)/42lib.a
OBJS_PATH		=	objs/minishell/
#============PATHS============#

CORE_PATH		=	srcs/core/
BUILTINS_PATH	=	srcs/builtins/
EXECUTOR_PATH	=	srcs/executor/
EXPANDER_PATH	=	srcs/expander/
LEXER_PATH		=	srcs/lexer/
NODE_PATH		=	srcs/node_fncs/
PARSER_PATH		=	srcs/parser/
SIGNALS_PATH	=	srcs/sginals/
WILDCARD_PATH	=	srcs/wildcards/

SRCS_PATH		=	$(CORE_PATH)		\
					$(BUILTINS_PATH)	\
					$(EXECUTOR_PATH)	\
					$(EXPANDER_PATH)	\
					$(LEXER_PATH)		\
					$(NODE_PATH)		\
					$(PARSER_PATH)		\
					$(SIGNALS_PATH)		\
					$(WILDCARD_PATH)	\

#=============FILES=============#

CORE_FILES		=	ms_main				\
					utils				\

BUILTINS_FILES	=	builtins_core		\
					cd					\
					echo				\
					exit				\
					export				\
					pwd					\
					unset				\

EXECUTOR_FILES	=	executor_core		\
					executor_main		\
					executor_main		\
					executor_utils2		\
					fill_cmd_table		\
					node_manager		\
					redir				\
					redirections		\
					special_split		\

EXPANDER_FILES	=	expander_core		\
					expander_env_rep	\
					expander_splitter	\
					expander_utils		\

LEXER_FILES		=	lex					\
					lex_utils			\

NODE_FILES		=	free_nodes			\
					ft_nodeadd_back		\
					ft_nodelast			\
					node_utils			\

PARSER_FILES	=	parser_core			\
					parser_errors		\
					parser_utils		\

SIGNALS_FILES	=	signals_core		\
					signal_handler		\

WILDCARD_FILES	=	wildcards_core		\
					dir_fncs			\

RAW_FILES		=	$(CORE_FILES)		\
					$(BUILTINS_FILES)	\
					$(EXECUTOR_FILES)	\
					$(EXPANDER_FILES)	\
					$(LEXER_FILES)		\
					$(NODE_FILES)		\
					$(PARSER_FILES)		\
					$(SIGNALS_FILES)	\
					$(WILDCARD_FILES)	\

#=============SRCS=============#

CORE_SRC		=	$(addprefix $(CORE_PATH), $(addsuffix .c, $(CORE_FILES)))
BUILTINS_SRC	=	$(addprefix $(BUILTINS_PATH), $(addsuffix .c, $(BUILTINS_FILES)))
EXECUTOR_SRC	=	$(addprefix $(EXECUTOR_PATH), $(addsuffix .c, $(EXECUTOR_FILES)))
EXPANDER_SRC	=	$(addprefix $(EXPANDER_PATH), $(addsuffix .c, $(EXPANDER_FILES)))
LEXER_SRC		=	$(addprefix $(LEXER_PATH), $(addsuffix .c, $(LEXER_FILES)))
NODE_SRC		=	$(addprefix $(NODE_PATH), $(addsuffix .c, $(NODE_FILES)))
PARSER_SRC		=	$(addprefix $(PARSER_PATH), $(addsuffix .c, $(PARSER_FILES)))
SIGNALS_SRC		=	$(addprefix $(SIGNALS_PATH), $(addsuffix .c, $(SIGNALS_FILES)))
WILDCARD_SRC	=	$(addprefix $(WILDCARD_PATH), $(addsuffix .c, $(WILDCARD_FILES)))

SRC 			=	$(CORE_SRC)			\
					$(BUILTINS_SRC)		\
					$(EXECUTOR_SRC)		\
					$(EXPANDER_SRC)		\
					$(LEXER_SRC)		\
					$(NODE_SRC)			\
					$(PARSER_SRC)		\
					$(SIGNALS_SRC)		\
					$(WILDCARDS_SRC)	\


#=============OBJS============#

OBJS			=	$(addprefix $(OBJS_PATH), $(addsuffix .o, $(RAW_FILES)))


#SRC = srcs/core/ms_main.c \
srcs/core/utils.c \
srcs/builtins/builtins_core.c \
srcs/builtins/cd.c \
srcs/builtins/echo.c \
srcs/builtins/exit.c \
srcs/builtins/export.c \
srcs/builtins/unset.c \
srcs/expander/expander_core.c \
srcs/expander/expander_env_rep.c \
srcs/expander/expander_splitter.c \
srcs/expander/expander_utils.c \
srcs/lexer/lex_utils.c \
srcs/lexer/lex.c \
srcs/executor/executor_core.c \
srcs/executor/executor_main.c \
srcs/executor/executor_utils.c \
srcs/executor/executor_utils2.c \
srcs/executor/fill_cmd_table.c \
srcs/executor/node_manager.c \
srcs/executor/redir.c \
srcs/executor/redirections.c \
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

#OBJ = $(SRC:.c=.o)

RM = rm -f
ARRC = ar rc

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

INCLUDES = -I includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I /Users/$(USER)/.brew/opt/readline/include
RD_FLAGS = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib/


all:
	$(SRCS)



#$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
#	mkdir -p $(OBJS_PATH)
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) $(INC_FLAG) -o $(NAME)
#	@echo "$(WHT)Compiling 42lib...$(EOC)"
#	make -C 42lib/
#	@echo "$(WHT)Compiling minishell...$(EOC)"
#	@echo "$(GREEN)minishell build completed.$(EOC)"



clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	$(RM) $(OBJ)
	@echo "$(GREEN)clean done.$(EOC)"

fclean: clean
	make fclean -C 42lib/
	@echo "$(WHT)Removing binary -files...$(EOC)"
	$(RM) $(NAME)
	@echo "$(GREEN)fclean done.$(EOC)"

run: all
	./$(NAME)

re: fclean all

.PHONY: clean re fclean all m
