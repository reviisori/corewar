/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 22:41:37 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:05:37 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] != '\0' && !(ft_isdigit(str[i])))
		i++;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			n = (n * 10) + (str[i] - 48);
			i++;
		}
		else
			break ;
	}
	return (n * sign);
}
