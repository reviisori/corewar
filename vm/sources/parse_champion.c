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

void	parse_champion(t_info *info, char *file, int *id)
{
	static int	taken_ids[MAX_PLAYERS];
	int			fd;

	if (taken_ids[*id])
		error_handler(DUPLICATE_PLAYER_ID, info);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(strerror(errno), info);
	if (close(fd) == -1)
		error_handler(strerror(errno), info);
}
