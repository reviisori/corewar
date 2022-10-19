/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:13:37 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/19 20:35:58 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** creates a size_t array of size @size and fills it with zeros and returns it
*/
size_t	*ft_zeros(size_t size)
{
	size_t	*arr;
	size_t	i;

	arr = (size_t *)malloc(sizeof(size_t) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
