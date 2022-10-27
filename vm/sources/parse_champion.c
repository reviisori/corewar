/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:01 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/25 16:06:02 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	read_magic_header(int fd)
{
	char			buf[HEADER_SIZE];
	unsigned int	header;
	int				i;

	if (read(fd, buf, HEADER_SIZE) == -1)
		error_handler(strerror(errno));
	header = 0x00000000;
	i = -1;
	while (++i < HEADER_SIZE)
	{
		continue ;
		//continue here
	}
	if (header != COREWAR_EXEC_MAGIC)
		error_handler(HEADER_ERROR);
}

void	parse_champion(t_info *info, char *file, int *id)
{
	int	player_index;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(strerror(errno));
	read_magic_header(fd);
	info->champion_count++;
	if (info->champion_count == MAX_PLAYERS)
		error_handler(TOO_MANY_PLAYERS);
	player_index = set_player_id(id, info->champions);
	save_champion(fd, info->champions[player_index], file);
	if (close(fd) == -1)
		error_handler(strerror(errno));
}
