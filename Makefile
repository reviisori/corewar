# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:19:09 by asuikkan          #+#    #+#              #
#    Updated: 2022/12/07 16:19:11 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_VM  = corewar

ASM_DIR  = ./assembler
VM_DIR   = ./vm

EOC		 = \033[0m
GREEN	 = \033[32m
BLUE	 = \033[34m
SALMON	 = \033[38;5;203m
PURPLE	 = \033[38;5;134m
LGRAY	 = \033[38;5;244m
GOLD 	 = \033[38;5;136m
SILVER	 = \033[38;5;247m
RUST	 = \033[38;5;130m
BLACK	 = \033[38;5;236m
WHITE	 = \033[38;5;231m

all: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM):
	@make -C $(ASM_DIR)
	@mv $(ASM_DIR)/$(NAME_ASM) ./

$(NAME_VM):
	@make -C $(VM_DIR)
	@mv $(VM_DIR)/$(NAME_VM) ./

clean:
	@make -C $(ASM_DIR) clean
	@make -C $(VM_DIR) clean

fclean: clean
	@rm -rf $(NAME_ASM)
	@echo "$(PURPLE)[asm]$(EOC) $(LGRAY)Executable $(WHITE)$(NAME_ASM)$(EOC) $(LGRAY)removed!$(EOC)"
	@rm -rf $(NAME_VM)
	@echo "$(BLUE)[vm]$(EOC) $(LGRAY)Executable $(WHITE)$(NAME_VM)$(EOC) $(LGRAY)removed!$(EOC)"

re: fclean all

.PHONY: clean fclean re
