/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:26:10 by rikikytt          #+#    #+#             */
/*   Updated: 2021/08/02 13:06:29 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	insert_digit(char *nb, unsigned long long tmp, int upper)
{
	if (upper && tmp >= 10)
	{
		return (nb[tmp] - 32);
	}
	else
	{
		return (nb[tmp]);
	}
}

char	*ft_itoa_base(unsigned long long n, int base, int upper)
{
	int					len;
	unsigned long long	tmp;
	char				*str;
	char				*nb;

	len = count_length(n, base);
	tmp = n;
	nb = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (0);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (n > 0 && len >= 0)
	{
		tmp = n % base;
		n = n / base;
		str[len] = insert_digit(nb, tmp, upper);
		len--;
	}
	return (str);
}
