##########DIRECTORIES########
INCLUDES = -I ../../includes/
RD_FLAGS2 	= -I /sgoinfre/goinfre/Perso/becastro/homebrew/Cellar/readline/8.1.2/include/readline/
OBJ_DIR	= ../../objs/minishell/
CFLAGS = -Wall -Wextra -Werror
############SRCS##############
SRC_FILES =	builtins_core		\
			exit				\
			cd					\
			export				\
			echo				\
			unset				\

###############UTILS##########
OBJF = .cache_exists

#####SUFFIX AND PREFIX########
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

############RULES##############

all: $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	rm $(OBJ)
