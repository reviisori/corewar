/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:26:47 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:07:43 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if ((!dst && !src) || !len)
		return (dst);
	if (len > 32767)
		return (dst);
	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (dst);
	while (i < len)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return ((char *)dst);
}
