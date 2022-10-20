/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:31:57 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:09:54 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (s2 == NULL)
		return (0);
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			s2[i] = f(i, (char)s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
}
