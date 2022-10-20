/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:16:02 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:06:02 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	tolongint(unsigned char *hex, int i, int prefix_len)
{
	long			nb;
	int				round;
	unsigned char	c;

	nb = 0;
	round = 0;
	while ((i - prefix_len) >= 0)
	{
		c = hex[i];
		if (c >= 'A' && c <= 'F')
			nb += (c - 55) << round;
		else if (c >= '0' && c <= '9')
			nb += (c - 48) << round;
		else
			return (-1);
		i -= 2;
		round += 8;
	}
	return (nb);
}

static long	convert(unsigned char *hex, int len, int prefix_len)
{
	long	ones;
	long	sixteens;

	ones = tolongint(hex, len - 1, prefix_len);
	if (ones == -1)
		return (0);
	sixteens = tolongint(hex, len - 2, prefix_len) * 16;
	if (sixteens == -1)
		return (0);
	return (ones + sixteens);
}

/*
** converts the passed hexadecimal value to a long integer and returns it
**
** can handle hex values with or without the prefix "0x" (or "0X").
** returns 0 if the string has non-hex digits (anything else than [0-9a-fA-F]).
*/
long int	ft_hextol(const unsigned char *str)
{
	int				i;
	int				len;
	unsigned char	*hex;
	int				prefix_len;
	long			ret;

	len = ft_strlen((char *)str);
	hex = (unsigned char *)malloc(sizeof(char) * len);
	if (!hex)
		return (0);
	i = 0;
	while (i < len)
	{
		hex[i] = ft_toupper(str[i]);
		i++;
	}
	prefix_len = 2 * (len > 2 && hex[0] == '0' && hex[1] == 'X');
	ret = convert(hex, len, prefix_len);
	free(hex);
	return (ret);
}
