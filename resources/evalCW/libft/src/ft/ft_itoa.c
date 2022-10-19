/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:38:35 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:06:33 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*positive(char *str, int len, int n)
{
	int		nb;

	if (!str)
		return (0);
	len--;
	while (len >= 0)
	{
		nb = n;
		str[len--] = (nb % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static char	*negative(char *str, int len, int n)
{
	int		nb;

	if (!str)
		return (0);
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	n = n * -1;
	while (len > 0)
	{
		nb = n;
		str[len--] = (nb % 10) + '0';
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nb;

	len = 1;
	nb = n;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	if (n < 0 && n > -2147483648)
		str = negative(ft_strnew(len + 1), len, n);
	else if (n == -2147483648)
		str = negative(ft_strnew(len + 3), len, n);
	else
		str = positive(ft_strnew(len), len, n);
	return (str);
}
