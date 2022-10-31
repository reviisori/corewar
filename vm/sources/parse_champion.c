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

static void	read_magic_header(int fd, char *file)
{
	unsigned char	buf[HEADER_SIZE];
	unsigned int	header;

	if (read(fd, buf, HEADER_SIZE) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	header = big_endian_converter(buf, HEADER_SIZE);
	if (header != COREWAR_EXEC_MAGIC)
		error_handler(HEADER_ERROR, file, 0, 0);
}

void	parse_champion(t_info *info, char *file, int *id)
{
	int	player_index;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(OPEN_PREFIX, strerror(errno), 0, 0);
	read_magic_header(fd, file);
	info->champion_count++;
	if (info->champion_count > MAX_PLAYERS)
		error_handler(TOO_MANY_PLAYERS, NULL, 0, 0);
	player_index = set_player_id(id, info->champions);
	save_champion(fd, &info->champions[player_index], file);
	if (close(fd) == -1)
		error_handler(CLOSE_PREFIX, strerror(errno), 0, 0);
}
