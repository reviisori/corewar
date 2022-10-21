# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 14:15:24 by altikka           #+#    #+#              #
#    Updated: 2022/10/21 17:08:22 by altikka          ###   ########.fr        #
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

EOC = \033[0m
LGRAY = \033[38;5;244m
GOLD = \033[38;5;136m
SILVER = \033[38;5;247m
BLACK = \033[38;5;236m
WHITE = \033[38;5;231m
GREEN = \033[38;5;70m
RED = \033[38;5;124m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLGS) $(OBJS) -o $(NAME) $(LIB) $(INCS)
	@echo "$(EOC)$(LGRAY)[asm] $(SILVER)Compiling...$(EOC)"
	@echo "$(LGRAY)[asm] $(GOLD)Compiled successfully!$(EOC)"

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
