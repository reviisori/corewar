/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:55:19 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/23 17:02:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//static u_int16_t ushort_to_bigendian(u_int16_t nbr)
//{
//	u_int16_t	ret;

//	ret = (nbr & 0xFF00) >> 8;
//	ret = (nbr & 0x00FF) << 8 | ret;
//	return (ret);
//}

static u_int32_t uint_to_bigendian(u_int32_t nbr)
{
	u_int32_t	ret;

	ret = (nbr & 0xFF000000) >> 24;
	ret = (nbr & 0x000000FF) << 24 | ret;
	ret = (nbr & 0x00FF0000) >> 8 | ret;
	ret = (nbr & 0x0000FF00) << 8 | ret;
	return (ret);
}

static void	write_header(t_sh *d, const int fd)
{
	u_int32_t	magic;
	u_int32_t	exec_size;
	size_t		i;

	magic = uint_to_bigendian(d->header.magic);
	write(fd, &magic, 4);
	i = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		if (d->header.prog_name[i])
			write(fd, &d->header.prog_name[i], 1);
		else
			write(fd, "\0", 1);
		i++;
	}
	exec_size = uint_to_bigendian(d->byte);
	write(fd, &exec_size, 4);
	exit(0);
}

int	write_file(t_sh *d, const int fd)
{
	write_header(d, fd);
	return (1);
}
