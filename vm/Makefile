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

NAME		= corewar
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address #-Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits -O3
SRC_FILES	= main.c arguments.c error.c options_champion.c 			\
			  options_text_op.c parse_champion.c champion_id.c			\
			  save_champion.c big_endian_convert.c check_champions.c	\
			  game.c
SRCS_DIR	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_DIR	= ./objects/
OBJS		= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
INC_DIR		= ./includes/
SHR_INC		= ../shared/includes/
LIB_DIR		= ../libft
LIB			= -L $(LIB_DIR) -lft
PRINTF_INC	= ../libft/ft_printf/includes

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
	@$(CC) -I $(INC_DIR) -I $(LIB_DIR) -I $(PRINTF_INC) -I $(SHR_INC) -c $(CFLAGS) $< -o $@

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)/libft.a

re: fclean all
