##########DIRECTORIES########
INCLUDES = 	-I ../../includes/	\
			-I /Users/$(USER)/.brew/opt/readline/include \
			-I /usr/include/readline \

OBJ_DIR	= ../../objs/minishell/

CFLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3
############SRCS##############
SRC_FILES =	ms_main		\
			utils
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
