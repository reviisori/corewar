/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:55:19 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/23 16:47:08 by altikka          ###   ########.fr       */
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
	size_t		i;

	magic = uint_to_bigendian(d->header.magic);
	write(fd, &magic, 4);
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (d->header.prog_name[i])
			ft_dprintf(fd, "%X", d->header.prog_name[i]);
		else
			ft_dprintf(fd, "%02X", 0);
		i++;

	}
	exit(0);
}

int	write_file(t_sh *d, const int fd)
{
	write_header(d, fd);
	return (1);
}
