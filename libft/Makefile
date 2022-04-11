# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 11:18:00 by ksadiku           #+#    #+#              #
#    Updated: 2022/04/05 15:05:56 by ksadiku          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strlcat.c ft_strcat.c ft_strncat.c ft_strncpy.c ft_strcpy.c ft_strchr.c\
ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strdup.c ft_strlen.c ft_strcmp.c\
ft_strncmp.c ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memmove.c ft_memset.c\
ft_memcmp.c ft_bzero.c ft_atoi.c ft_toupper.c ft_tolower.c ft_isalnum.c\
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memdel.c\
ft_strnew.c ft_strdel.c ft_strclr.c ft_striteri.c ft_striter.c ft_strmap.c\
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
ft_strsplit.c ft_itoa.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putendl.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
ft_replace_c.c ft_replace_word.c ft_intlen.c ft_isspace.c ft_realloc.c\
get_next_line.c ft_free_array.c ft_free.c ft_strlenc.c ft_sqrt.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/
NOTNEED = *~

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I $(HEADER) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(NOTNEED)


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re