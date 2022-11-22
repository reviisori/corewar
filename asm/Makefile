# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 14:15:24 by altikka           #+#    #+#              #
#    Updated: 2022/11/22 16:05:56 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= asm

CC			= gcc

CFLGS		= -Wall -Wextra -Werror

INCS		= -I./includes -I../libft -I../libft/ft_printf/includes -I../shared/includes

SRC_FILES	= main.c \
			  main_utils.c \
			  parse.c \
			  init.c \
			  lex.c \
			  lex_utils.c \
			  lex_tokenization.c \
			  lex_endof.c \
			  lex_comment.c \
			  lex_header.c \
			  lex_command.c \
			  lex_argument.c \
			  lex_label.c \
			  lex_comma.c \
			  check_labels.c \
			  source_read.c \
			  source_utils.c \
			  cleanup_source.c \
			  cleanup_lex.c \
			  assemble.c \
			  write_file.c \
			  write_utils.c

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
RUST = \033[38;5;130m
BLACK = \033[38;5;236m
WHITE = \033[38;5;231m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLGS) $(OBJS) -o $(NAME) $(LIB) $(INCS)
	@echo "$(LGRAY)[asm] $(GOLD)Compiled successfully!$(EOC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(EOC)$(LGRAY)[asm] $(SILVER)Compiling...$(EOC)"
	@make -sC $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLGS) $< -o $@ $(INCS)

clean:
	@make -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(LGRAY)[asm] $(RUST)Deleting object directory...$(EOC)"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(LGRAY)[asm] $(RUST)Executable $(WHITE)$(NAME)$(EOC) $(RUST)removed!$(EOC)"

re: fclean all

.PHONY: all clean fclean re
