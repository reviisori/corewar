# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 14:15:24 by altikka           #+#    #+#              #
#    Updated: 2022/10/21 15:22:08 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= asm

CC			= gcc

CFLGS		= -Wall -Wextra -Werror

INCS		= -I./includes -I../libft -I../libft/ft_printf/includes

SRC_FILES	= main.c
SRC_DIR		= ./src/
SRCS		= $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJ_DIR		= ./obj/
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

LIB_DIR		= ../libft/
LIB			= -L $(LIB_DIR) -lft

GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
RED		= "\x1b[31m"
EOC		= "\x1b[0m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLGS) $(OBJS) -o $(NAME) $(LIB) $(INCS)
	@echo $(RED)"Compiling..."$(EOC)
	@echo $(GREEN)"Compiled successfully."$(EOC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLGS) $< -o $@ $(INCS)

clean:
	@make -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)

re: fclean all
