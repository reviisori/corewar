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

/*static void	save_champion(int fd, t_champions )
{

}*/

static void	read_magic_header(int fd)
{
	int	*header;

	if (read(fd, header, sizeof(int)) == -1)
		error_handler(strerror(errno));
	if (*header != COREWAR_EXEC_MAGIC)
		error_handler(HEADER_ERROR);
}

static void	organize_players(t_champion *ch_list[], int index, int *taken_ids)
{
	int	j;
	int	target;

	if (!ch_list[index])
		return ;
	target = MAX_PLAYERS - 1;
	j = MAX_PLAYERS;
	while (--j >= index)
	{
		if (!taken_ids[j])
		{
			ft_memcpy(ch_list[target], ch_list[j], sizeof(t_champion));
			target = j;
		}
	}
}

static int	set_player_id(int *id, t_champion *ch_list[])
{
	static int	taken_ids[MAX_PLAYERS];
	int			player_index;

	player_index = *id - 1;
	if (player_index >= 0)
	{
		if (taken_ids[player_index])
			error_handler(DUPLICATE_PLAYER_ID);
		organize_players(ch_list, player_index, taken_ids);
		taken_ids[player_index] = 1;
		*id = 0;
	}
}

void	parse_champion(t_info *info, char *file, int *id)
{
	int	player_index;
	int	fd;

	if (info->champion_count == MAX_PLAYERS)
		error_handler(TOO_MANY_PLAYERS);
	player_index = set_player_id(id, info->champions);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(strerror(errno));
	read_magic_header(fd);
	//save_champion(fd, &info->champions[]);
	if (close(fd) == -1)
		error_handler(strerror(errno));
}
