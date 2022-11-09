##########DIRECTORIES########
INCLUDES =	-I ../../includes/	\
			-I /Users/$(USER)/.brew/opt/readline/include \
			-I /usr/include/readline \
			
OBJ_DIR	= ../../objs/minishell/
RD_FLAGS	= -I /sgoinfre/goinfre/Perso/$(USER)/homebrew/Cellar/readline/8.1.2/include/readline/

############SRCS##############
SRC_FILES =	signal_handler		\
			signals_core		\

###############UTILS##########
OBJF = .cache_exists

#####SUFFIX AND PREFIX########
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

############RULES##############

all: $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(RD_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	rm $(OBJ)
