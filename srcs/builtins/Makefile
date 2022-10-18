##########DIRECTORIES########
INCLUDES = -I ../../includes/
OBJ_DIR	= ../../objs/minishell/

############SRCS##############
SRC_FILES =	builtins_core		\

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
