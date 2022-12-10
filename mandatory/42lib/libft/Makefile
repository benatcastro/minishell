CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBRARIES_DIR = libraries/
INCLUDES = ../../includes/
OBJ_DIR = ../../objs/42lib/


SRC_FILES =	ft_isalpha			\
			ft_isblank			\
			ft_isdigit			\
			ft_isalnum			\
			ft_isascii			\
			ft_isprint			\
			ft_strlen			\
			ft_memset			\
			ft_bzero			\
			ft_memcpy			\
			ft_memmove			\
			ft_strlcpy			\
			ft_strlcat			\
			ft_toupper			\
			ft_tolower			\
			ft_strchr			\
			ft_strrchr			\
			ft_strncmp			\
			ft_memchr			\
			ft_memcmp			\
			ft_strnstr			\
			ft_atoi				\
			ft_calloc			\
			ft_strdup			\
			ft_substr			\
			ft_strjoin			\
			ft_strtrim			\
			ft_split			\
			ft_itoa				\
			ft_strmapi			\
			ft_striteri			\
			ft_putchar_fd		\
			ft_putstr_fd		\
			ft_putendl_fd		\
			ft_putnbr_fd		\
			ft_lstnew			\
			ft_lstadd_front		\
			ft_lstsize			\
			ft_lstlast			\
			ft_lstadd_back		\
			ft_lstdelone		\
			ft_lstclear			\
			ft_lstiter			\
			ft_lstmap			\
			ft_isempty			\
			ft_checkext			\
			ft_checkfile		\
			ft_getfile_size		\
			ft_chr_in_set		\
			ft_doublestrdup		\
			ft_doublefree		\
			ft_doublestrlen		\
			ft_doubleprint		\
			ft_strcmp			\
			ft_append_char		\
			ft_split_in_set		\
			ft_str_replace		\
			get_next_line		\
			get_next_line_utils	\
			ft_put				\
			ft_puthexa			\
			ft_printerr			\

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists


all: $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
