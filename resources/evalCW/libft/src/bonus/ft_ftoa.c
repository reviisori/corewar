/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:36:35 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:05:57 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	round_wholes:
**	- exists only because of school's max 25 lines per function limit
**	1) turns string into long long int
**	2) increments it by one
**	3) converts it back to a string
**	4) frees original string
*/

static char	*round_wholes(char **str)
{
	char	*rounded;

	rounded = ft_itoa_base((ft_atoll(*str) + 1), 10, 0);
	free(*str);
	return (rounded);
}

/*
**	f_roundup:
**	- Takes a float value that has been turned into a sequence of numbers,
**	  represented as characters in a string and the amount of decimals.
**	- Returns a string that has been rounded up, as if the string was
**	  originally an integer.
*/

static char	*f_roundup(char *str)
{
	int		i;

	i = (ft_strlen(str) - 2);
	if (i >= 0 && str[i + 1] >= '5')
	{
		if (str[i] != '9')
			str[i] = str[i] + 1;
		else
		{
			while (i - 1 >= 0)
			{
				str[i] = '0';
				if (str[i - 1] != '9')
				{
					str[i - 1] = str[i - 1] + 1;
					break ;
				}
				i--;
			}
		}
	}
	if (i == 0)
		return (round_wholes(&str));
	else
		return (str);
}

/*
**	format_decimals:
**	- Takes a char pointer that points to the first decimal number character
**	- Moves all elements forward by 1 and places a decimal point to the start,
**	  thus removing the last "extra" decimal which was used only for rounding up
**	- Returns the newly formatted decimal part
*/

static char	*format_decimals(char *decimals)
{
	int		len;

	len = ft_strlen(decimals) - 1;
	while (len > 0)
	{
		decimals[len] = decimals[len - 1];
		len--;
	}
	decimals[0] = '.';
	return (decimals);
}

/*
**	split_n_join:
**	param1: original float value
**	param2: desired precision
**	param3: amount of numbers on the left side of the decimal point
**	param4: 1 (true) if original float value is < 1.0, otherwise 0 (false)
**
**	- turns all the digits of the float to one sequence of numbers
**	- sends that sequence as a string on for rounding up
**	- splits the rounded up string to whole & decimal number strings
**	  based on the given integer count
**	- joins them together, formatted properly and returns it
*/

static char	*split_n_join(long double nb, int prec, int int_count, int olt1)
{
	char				*str;
	char				*ints;
	char				*final;
	int					orig_prec;

	orig_prec = prec - 1;
	if (orig_prec < 0)
		prec = 7;
	while (prec != 0)
	{
		nb *= 10.0;
		prec--;
	}
	str = f_roundup(ft_itoa_base((unsigned long long)nb, 10, 0));
	if (olt1)
		str[0] = str[0] - 1;
	ints = ft_strndup(str, int_count);
	if (orig_prec == 0)
	{
		free(str);
		return (ints);
	}
	final = ft_strjoin_free(ints, format_decimals(ft_strdup(str + int_count)));
	free(str);
	return (final);
}

/*
**	ft_ftoa takes a float and returns its value with the desired precision
**	as a string.
**
**	ft_ftoa:
**	- temporarily gets rid of the sign (if negative),
**	- counts the amount of integers
**	- sends that data onward for further processing,
**	- attaches the possible negative sign and
**	- returns the processed (rounded up) string.
*/

char	*ft_ftoa(long double nb, int precision)
{
	char			sign;
	char			*str;
	long double		tmp;
	int				int_count;

	sign = '+';
	if (nb < 0)
	{
		sign = '-';
		nb *= -1.0;
	}
	tmp = nb;
	int_count = 1;
	while (tmp >= 10.0)
	{
		tmp /= 10.0;
		int_count++;
	}
	if (nb < 1.0)
		str = split_n_join(nb + 1.0, precision + 1, int_count, 1);
	else
		str = split_n_join(nb, precision + 1, int_count, 0);
	if (sign == '-')
		str = ft_strjoin_free(ft_strdup("-"), str);
	return (str);
}
