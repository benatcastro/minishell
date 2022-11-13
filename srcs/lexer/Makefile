##########DIRECTORIES########
INCLUDES = -I ../../includes/
OBJ_DIR	= ../../objs/minishell/
CFLAGS		= -Wall -Werror -Wextra
############SRCS##############
SRC_FILES =	lex_utils\
			lex

#####SUFFIX AND PREFIX########
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

############RULES##############

all: $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJ)
