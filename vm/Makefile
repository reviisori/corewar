# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:20:00 by asuikkan          #+#    #+#              #
#    Updated: 2022/10/20 16:20:02 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address #-Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits -O3
SRC_FILES	= main.c arguments.c
SRCS_DIR	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_DIR	= ./objects/
OBJS		= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
LIB_DIR		= ../libft
LIB			= -L $(LIB_DIR) -lft

GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
RED		= "\x1b[31m"
EOC		= "\x1b[0m"

all: $(NAME)
	@echo $(GREEN) "Compiled" $(EOC)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo $(RED) "Compiling..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)/libft.a

re: fclean all
