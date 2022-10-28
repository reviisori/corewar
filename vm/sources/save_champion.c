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
	unsigned char	buf[CODE_SIZE];
	unsigned int	size;

	if (read(fd, buf, CODE_SIZE) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
	size = big_endian_converter(buf, CODE_SIZE);
	if (size > CHAMP_MAX_SIZE)
		error_handler(CHAMP_TOO_BIG, file, size, CHAMP_MAX_SIZE);
	champion->code_size = size;
}

static void	save_name(int fd, t_champion *champion)
{
	if (read(fd, champion->name, PROG_NAME_LENGTH) == -1)
		error_handler(READ_PREFIX, strerror(errno), 0, 0);
}

void	save_champion(int fd, t_champion *champion, char *file)
{
	char	temp[4];

	save_name(fd, champion);
	read(fd, temp, 4); //temp read() call to read the four null bytes after name (implement something better)
	save_code_size(fd, champion, file);
	//save_comment(fd, champion);
	//save_code(fd, champion);
}
