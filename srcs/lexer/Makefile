##########DIRECTORIES########
INCLUDES = -I ../../includes/
OBJ_DIR	= ../../objs/minishell/

############SRCS##############
SRC_FILES =	lexer_core		\
			replace_quotes	\

#####SUFFIX AND PREFIX########
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

############RULES##############

all: $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJ)
