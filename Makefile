# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 10:49:52 by ksadiku           #+#    #+#              #
#    Updated: 2023/02/24 18:26:54 by ksadiku          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

H_FOLDER		=	include
C_FOLDER		=	src
OBJ_FOLDER		=	obj
FOLDER_LIST		=	$(H_FOLDER) $(C_FOLDER) $(OBJ_FOLDER)

H_FILES			=	ft_printf.h
C_FILES			=	ft_printf.c ft_printchr.c ft_numbers.c ft_printstr.c ft_utils.c ft_printnumber.c
H_PATHS			=	$(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS			=	$(addprefix $(C_FOLDER)/, $(C_FILES))
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS			=	-Wall -Wextra -Werror
FT_INC			=	-I libft/includes
FT_LIB			=	libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): pre_requisites $(OBJ_PATHS)
	@touch pre_requisites
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ_PATHS)

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS)
	cc $(C_FLAGS) $(FT_INC) -I $(H_FOLDER) -c $< -o $@

pre_requisites: $(FOLDER_LIST) $(H_PATHS) $(C_PATHS)

$(FOLDER_LIST):
	@mkdir $@

$(H_PATHS):
	@touch $@

$(C_PATHS):
	@touch $@

.PHONY: print_files
print_files:
	@echo "H paths:   $(H_PATHS)"
	@echo "C paths:   $(C_PATHS)"
	@echo "OBJ paths: $(OBJ_PATHS)"
	@echo "C flags:   $(C_FLAGS)"
	@echo ""

.PHONY: clean
clean:
	-@rm -rf $(OBJ_PATHS)
	-@make clean -C libft
	@echo "All object files are removed!"

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)
	-@rm -rf $(OBJ_FOLDER)
	-@rm -f pre_requisites
	@make fclean -C libft
	@echo "$(NAME) file is removed!"

.PHONY: re
re: fclean all
