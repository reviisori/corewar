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

/* Headers for libraries and preprocessor macros */
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

/* Usage */
# define USAGE "Usage: ./corewar [-dump N] <[-n N] champion1.cor> <...>\n\
\t############### TEXT OUTPUT MODE ################\n\
\t\t-dump N\t: Dumps memory to standard output after N cycles and \
quits the game\n\
\t\t-d N\t: Same as -dump\n\
\t############### CHAMPION OPTIONS ################\n\
\t\t-n N\t: Sets the champions player number to N"

/* Champion related errors */
# define INVALID_PLAYER_ID "Invalid player number"
# define DUPLICATE_PLAYER_ID "Player already exists"
# define TOO_MANY_PLAYERS "Too many players"

/* File related errors */
# define CHAMP_TOO_BIG "File %s ihas too large a code (%d bytes > %d bytes)"
# define HEADER_ERROR "Invalid header"

/* Option macros, struct, functions and the jump table implemented for them */
# define OPTIONS "dn"
# define OPTION_COUNT 2

/* Macros describing .cor file standard */
# define HEADER_SIZE 4		/* sizeof(unsigned int) */

typedef struct s_options
{
	int	next_id;
	int	dump;
}		t_options;

int		set_player_number(t_options *opts, char *nbr);
int		set_dump(t_options *opts, char *nbr);

typedef int					(*t_jump_opts)(t_options *, char *);

static const t_jump_opts	g_jump_table[OPTION_COUNT] = {
	set_dump,
	set_player_number
};

/* Struct for champion information */
typedef struct s_champion
{
	int				id;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				code_size;
	unsigned char	code[CHAMP_MAX_SIZE];
}					t_champion;

/* Head struct which includes all relevant information for the VM */
typedef struct s_info
{
	int			dump_cycles;
	int			champion_count;
	t_champion	*champions[MAX_PLAYERS];
}				t_info;

/* VM functions */
int		set_player_id(int *id, t_champion *ch_list[]);

void	error_handler(char *message);
void	error_handler_champ_size(char *message, char *file, int size, int max);
void	parse_champion(t_info *info, char *file, int *id);
void	read_arguments(int argc, char **argv, t_info *info);
void	save_champion(int fd, t_champion *champion, char *file);
void	usage_exit(void);

#endif
