/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes_toint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:47:28 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 21:46:55 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** treats the byte pointed to by @bytes as the most significant byte of a
** series of @n bytes forward.
*/
size_t	ft_bytes_toint(const unsigned char *bytes, int n)
{
	size_t	nbr;
	int		bits;

	if (!bytes || n <= 0 || (unsigned long)n > sizeof(size_t))
		return (0);
	nbr = 0;
	bits = 0;
	while (--n >= 0)
	{
		nbr += (size_t)bytes[n] << bits;
		bits += 8;
	}
	return (nbr);
}
