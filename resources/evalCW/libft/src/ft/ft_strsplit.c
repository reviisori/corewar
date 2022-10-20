/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:48:03 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:10:45 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_counter(char const *s, char c, unsigned int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && s[i - 1] == c && j == 0)
			break ;
		j++;
	}
	return (j + 1);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	char			**str_arr;

	i = 0;
	start = 0;
	str_arr = (char **)malloc(sizeof(char *) * ft_ptr_counter(s, c, i));
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i++] == c && s[i] != '\0')
			start++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && s[i - 1] == c)
			break ;
		str_arr[j++] = ft_strsub(s, start, (i - start));
		start = i;
	}
	str_arr[j] = NULL;
	if (str_arr == NULL)
		return (0);
	return (str_arr);
}
