/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:07:33 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:07:22 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		a;

	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == a)
			return ((unsigned char *)s + i);
		else
			i++;
	}
	return (NULL);
}
