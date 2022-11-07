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
# include <limits.h>
# include <stdbool.h>

/* Usage */
# define USAGE "Usage: ./corewar [-dump N] <[-n N] champion1.cor> <...>\n\
\t############### TEXT OUTPUT MODE ################\n\
\t\t-dump N\t: Dumps memory to standard output after N cycles and \
quits the game\n\
\t\t-d N\t: Same as -dump\n\
\t############### CHAMPION OPTIONS ################\n\
\t\t-n N\t: Sets the champions player number to N"

/* System call related error prefixes (perror emulation) */
# define READ_PREFIX "read(): %s"
# define OPEN_PREFIX "open(): %s"
# define CLOSE_PREFIX "close(): %s"

/* Champion related errors */
# define PLAYER_NB_TOO_SMALL "Player number too small (%s <= 0)"
# define PLAYER_NB_TOO_BIG "Player number too big (%s > %d)"
# define DUPLICATE_PLAYER_ID "Trying to create champion with duplicate number"
# define TOO_MANY_PLAYERS "Too many champions"
# define NON_SEQUENTIAL_NUMBERS "Player numbers are not sequential"

/* File related errors */
# define CHAMP_TOO_BIG "File %s has too large a code (%u bytes > %u bytes)"
# define CODE_SIZE_DIFF "File %s has a code size that \
differs from what its header says"
# define HEADER_ERROR "File %s has an invalid header"

/* Option macros, struct, functions and the jump table implemented for them */
# define OPTIONS "dn"
# define OPTION_COUNT 2

/* Macros describing .cor file standard */
# define HEADER_SIZE 4		/* sizeof(unsigned int) */
# define CODE_SIZE 4		/* sizeof(unsigned int) */
# define NULL_TERM 4		/* the size of null terminators in .cor files */

/* General macros */
# define BITS_IN_BYTE 8
# define MAX_UINT 0xFFFFFFFF

typedef struct s_options
{
	int	next_id;
	int	dump;
}		t_options;

int				set_player_number(t_options *opts, char *nbr);
int				set_dump(t_options *opts, char *nbr);

typedef int					(*t_jump_opts)(t_options *, char *);

static const t_jump_opts	g_jump_table[OPTION_COUNT] = {
	set_dump,
	set_player_number
};

/* Struct for champion information */
typedef struct s_champion
{
	int					id;
	unsigned char		name[PROG_NAME_LENGTH + 1];
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned int		code_size;
	unsigned char		code[CHAMP_MAX_SIZE];

	unsigned int		last_live;//needs to be init to 0;
	struct s_champion	*next;//or another way to find them
}					t_champion;

/* Carriage i.e. the offset that "plays the game", moving around memory
	and executing instructions */
typedef struct s_car
{
	unsigned int	index;// ≥ 1
	unsigned int	reg[REG_NUMBER + 1];// 1+15 registries, 0 never used 
	unsigned int	pc;//current position, always %MEM_SIZE
	bool			carry;
	
	unsigned char	op;//the current statement the car stands on
	unsigned int	last_live;//the last cycle the car declared alive
	unsigned int	wait;//cycles until current op tries to run and this car moves
	unsigned int	jump;// amount of bytes the car moves next jump, ≥ 1
	bool			alive;
	struct s_car	*next;
} t_car;

/* Head struct which includes all relevant information for the VM */
typedef struct s_info
{
	unsigned char	memory[MEM_SIZE];
	int				dump_cycles;
	int				champion_count;
	t_champion		champions[MAX_PLAYERS];

	unsigned int 	cycle;
	unsigned int 	next_check_cycle;
	int 			cycles_to_die;
	t_car			*liststart;
	unsigned int	lives_this_cycle;//live _statements_
	unsigned int	checks_after_mod;
}				t_info;

/* VM functions */
int				read_arguments(int argc, char **argv, t_info *info);
int				set_player_id(int *id, t_champion ch_list[]);

unsigned int	big_endian_converter(unsigned char *bytes, int size);

void			check_champions(t_champion ch_list[], int ch_count);
void			error_handler(char *message, char *arg1,
					unsigned int arg2, unsigned int arg3);
void			execute_cycles(t_info *info);
void			parse_champion(t_info *info, char *file, int *id);
void			print_usage(char *usage);
void			save_champion(int fd, t_champion *champion, char *file);
void			usage_exit(void);

/* Game functions */
int				run_game(t_info *info);

#endif
