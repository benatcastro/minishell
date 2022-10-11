##########DIRECTORIES########
INCLUDES = -I ../../includes/
OBJ_DIR	= ../../objs/minishell/

############SRCS##############
SRC_FILES =	ft_nodeadd_back	\
			ft_nodelast		\
			node_utils		\

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
