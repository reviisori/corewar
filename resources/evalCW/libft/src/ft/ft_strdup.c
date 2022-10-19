/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:27:21 by rkyttala          #+#    #+#             */
/*   Updated: 2022/04/26 16:39:17 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*s2;

	if (!s1)
		return (0);
	length = 0;
	while (s1[length] != '\0')
		length++;
	s2 = (char *)malloc(sizeof(char) * (length + 1));
	if (!s2)
		return (0);
	length = 0;
	while (s1[length] != '\0')
	{
		s2[length] = s1[length];
		length++;
	}
	s2[length] = '\0';
	return (s2);
}
