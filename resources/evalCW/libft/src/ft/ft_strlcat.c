/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:17:09 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:09:39 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < i)
		return (dstsize + ft_strlen(src));
	if (dstsize == i)
		k = dstsize - i;
	if (dstsize > i)
		k = dstsize - i - 1;
	while (j < k && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	i = i - j;
	return (i + ft_strlen(src));
}
