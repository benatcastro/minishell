#---------NAMES--------------
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
#---------GCC and FLAGS----------

RM			= rm -rf
CC 	 		= gcc
AR			= ar rc
CFLAGS 		= -Wall -Wextra -Werror
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = ../objs/42lib/
INC_DIR = includes/
LIB_DIR = ../libraries/


#---------------PREFIX and SUFFIX-----------------

SRC_LIBFT = $(addprefix $(SRC_DIR)libft/, $(addsuffix .c, $(FILES_LIBFT)))
OBJ_LIBFT = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_LIBFT)))

all: 42lib

42lib: libft
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*.o
	@ranlib $(LIB_DIR)$(LIB_NAME)

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)

libft: mk_dirs
	@make -C libft

gnl: mk_dirs
	@make -C gnl
	@echo "GNL Compiled"

clean:
	$(RM) ../objs/
	@clear
	@echo "Clean done"

fclean: clean
	@rm -rf ../objs$(LIB_DIR)
	@echo "Fclean done"
re: clean all
