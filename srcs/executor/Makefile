##########DIRECTORIES########
INCLUDES = -I ../../includes/
OBJ_DIR	= ../../objs/minishell/
#CFLAGS		= -Wall -Werror -Wextra
############SRCS##############
SRC_FILES =	executor_core		\
			executor_main		\
			executor_utils		\
			executor_utils2		\
			node_manager		\
			fill_cmd_table		\
			special_split		\
			redir				\
			redirections		\
#			linked_manager		\

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
