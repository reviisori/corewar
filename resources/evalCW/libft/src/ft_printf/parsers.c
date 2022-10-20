/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:36:06 by rkyttala          #+#    #+#             */
/*   Updated: 2021/05/02 18:11:10 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	scan_flags(char c, t_specs *specs)
{
	if (c == '#')
		specs->pound = 1;
	else if (c == '0')
		specs->zero = 1;
	else if (c == '-')
		specs->minus = 1;
	else if (c == '+')
		specs->plus = 1;
	else if (c == ' ')
		specs->space = 1;
	else
		return (0);
	return (1);
}

int	scan_width(char *format, t_specs *specs)
{
	char	*width;
	int		i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i > 0)
	{
		width = ft_strnew(i);
		if (!width)
			exit(1);
		i = 0;
		while (ft_isdigit(format[i]))
		{
			width[i] = format[i];
			i++;
		}
		if (i > 0)
			specs->width = ft_atoi(width);
		ft_liberator(1, &width);
	}
	return (i);
}

int	scan_precision(char *format, t_specs *specs, int i)
{
	char	*precision;

	i = 0;
	if (format[i] == '.')
	{
		while (ft_isdigit(format[i + 1]))
			i++;
		if (i == 0)
		{
			specs->precision = 0;
			return (1);
		}
		precision = ft_strnew(i);
		if (!precision)
			exit(1);
		i = 1;
		while (ft_isdigit(format[i]))
		{
			precision[i - 1] = format[i];
			i++;
		}
		specs->precision = ft_atoi(precision);
		ft_liberator(1, &precision);
	}
	return (i);
}

int	scan_length(char *format, t_specs *specs)
{
	if (format[0] == 'h')
	{
		if (format[1] == 'h')
		{
			specs->hh = 1;
			return (2);
		}
		specs->h = 1;
	}
	else if (format[0] == 'l')
	{
		if (format[1] == 'l')
		{
			specs->ll = 1;
			return (2);
		}
		specs->l = 1;
	}
	else if (format[0] == 'L')
		specs->long_dbl = 1;
	else
		return (0);
	return (1);
}

void	scan_specifier(char c, t_specs *specs)
{
	if (is_validspec(c))
		specs->type = c;
	else if (c != '\0')
	{
		ft_putchar(c);
		specs->type = '?';
	}
}
