/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:28 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/27 14:06:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static void	save_code(int fd, t_champion *champion)
{
	
}

static void	save_comment(int fd, t_champion *champion)
{

}*/

static void	save_code_size(int fd, t_champion *champion, char *file)
{
	int	size;

	if (read(fd, &size, sizeof(int)) == -1)
		error_handler(strerror(errno));
	if (size > CHAMP_MAX_SIZE)
		error_handler_champ_size(CHAMP_TOO_BIG, file, size, CHAMP_MAX_SIZE);
	champion->code_size = size;
}

static void	save_name(int fd, t_champion *champion)
{
	if (read(fd, champion->name, PROG_NAME_LENGTH + 1) == -1)
		error_handler(strerror(errno));
}

void	save_champion(int fd, t_champion *champion, char *file)
{
	save_name(fd, champion);
	save_code_size(fd, champion, file);
	//save_comment(fd, champion);
	//save_code(fd, champion);
}
