/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:16:11 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:10:59 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Trims leading and trailing whitespace from the given string,
** allocates new memory for the trimmed string and returns it.
*/
char	*ft_strtrim(char const *s)
{
	unsigned int		i;
	unsigned int		end;
	char				*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == ft_strlen(s))
	{
		str = "\0";
		return (str);
	}
	end = ft_strlen(s) - 1;
	while (end > 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	str = ft_strsub(s, i, (end + 1 - i));
	if (!str)
		return (0);
	else
		return (str);
}
