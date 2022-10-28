/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:54:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/28 11:54:21 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	big_endian_converter(unsigned char *bytes, int size)
{
	int				i;
	unsigned int	byte_count;
	unsigned int	byte;
	unsigned int	ret;

	ret = 0;
	byte_count = size - 1;
	i = -1;
	while (++i < size)
	{
		byte = bytes[i];
		byte = byte << BITS_IN_BYTE * byte_count;
		ret = ret | byte;
		byte_count--;
	}
	return (ret);
}
