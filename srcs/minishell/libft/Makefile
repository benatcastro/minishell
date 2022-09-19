# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 12:04:06 by umartin-          #+#    #+#              #
#    Updated: 2022/04/08 15:04:37 by umartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c\
ft_strnstr.c\
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strtrim.c \
ft_strjoin.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
get_next_line.c \
get_next_line_utils.c \
ft_printf.c \
ft_put.c \
ft_puthexa.c \
t_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \

OBJECTS = ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_isascii.o \
ft_isprint.o \
ft_strlen.o \
ft_memset.o \
ft_bzero.o \
ft_memcpy.o \
ft_memmove.o \
ft_strlcpy.o \
ft_strlcat.o \
ft_toupper.o \
ft_tolower.o \
ft_strchr.o \
ft_strrchr.o \
ft_strncmp.o \
ft_memchr.o \
ft_memcmp.o\
ft_strnstr.o\
ft_atoi.o \
ft_calloc.o \
ft_strdup.o \
ft_substr.o \
ft_strtrim.o \
ft_strjoin.o \
ft_split.o \
ft_itoa.o \
ft_strmapi.o \
ft_striteri.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putendl_fd.o \
ft_putnbr_fd.o \
get_next_line.o \
get_next_line_utils.o \
ft_printf.o \
ft_put.o \
ft_puthexa.o \
ft_lstnew.o \
ft_lstadd_front.o \
ft_lstsize.o \
ft_lstlast.o \
ft_lstadd_back.o \

CCFLAGS = -Wall -Werror -Wextra

CC = gcc
RM = rm -f
ARRC = ar rc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARRC) $(NAME) $(OBJECTS)

$(CSOURCE): $(SOURCE)
	$(CC) $(CCFLAGS) -c $(SOURCE)
	
clean: 
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re fclean all bonus