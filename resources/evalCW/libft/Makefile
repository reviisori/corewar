# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:43:31 by rkyttala          #+#    #+#              #
#    Updated: 2021/08/19 20:30:35 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ARCC = ar
ARFLAGS = -rcs
RAN = ranlib

SRC_PATH = src/
OBJ_PATH = obj/

LIBFT_DIR = ft/
BONUS_DIR = bonus/
GNL_DIR = gnl/
PF_DIR = ft_printf/

INC = includes

LIBFT_SRC =	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsplit.c \
			ft_memalloc.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putnstr.c \
			ft_putstr_fd.c \
			ft_putstr.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c

BONUS_SRC = ft_abs.c \
			ft_arrlen.c \
			ft_atoll.c \
			ft_bytes_toint.c \
			ft_digits_only.c \
			ft_ftoa.c \
			ft_hextol.c \
			ft_itoa_base.c \
			ft_liberator.c \
			ft_putpad.c \
			ft_strjoin_free.c \
			ft_zeros.c

GNL_SRC =	get_next_line.c

PF_SRC =	csp.c \
			di.c \
			octal.c \
			unsigned.c \
			hexadecimal.c \
			utils.c \
			ft_printf.c \
			parsers.c \
			validate.c \
			float.c

SRCS_NAME = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC)) \
			$(addprefix $(BONUS_DIR), $(BONUS_SRC)) \
			$(addprefix $(GNL_DIR), $(GNL_SRC)) \
			$(addprefix $(PF_DIR), $(PF_SRC))

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_DIRS = $(LIBFT_DIR) $(BONUS_DIR) $(GNL_DIR) $(PF_DIR)

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

MAKEFLAGS += --silent

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(addprefix $(OBJ_PATH), $(OBJ_DIRS))

$(NAME): message $(OBJS)
	$(ARCC) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GRN)$(NAME) compiled successfully$(EOC)"
	$(RAN) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

message:
	@echo "$(GRN)Compiling libft$(EOC)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

GRN = \033[0;32m
EOC = \033[0m

