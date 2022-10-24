/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:35:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/20 17:35:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdio.h>
# include <errno.h>

# define USAGE "Usage: ./corewar [-dump N] <[-n N] champion1.cor> <...>\n\
############### TEXT OUTPUT MODE ################\n\
\t-dump N\t: Dumps memory to standard output after N cycles and \
quits the game\n\
############### CHAMPION OPTIONS ###############\n\
\t-n N\t: Sets the champions player number to N"

# define INVALID_OPTION "Invalid option"

typedef struct s_champion
{
	int				id;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				code_size;
	unsigned char	code[CHAMP_MAX_SIZE];
}					t_champion;

typedef struct s_info
{
	int			dump_cycles;
	int			champion_count;
	int			current_id;
	t_champion	champions[MAX_PLAYERS];
}				t_info;

void	read_arguments(int argc, char **argv, t_info *info);
void	error_handler(char *message, t_info *info);

#endif
