/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:01:38 by rkyttala          #+#    #+#             */
/*   Updated: 2021/05/24 18:50:28 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	f_output_l(t_specs *specs, char *str, char sign, int len)
{
	if (is_signed(specs, sign))
	{
		ft_putchar(sign);
		if (specs->pound && specs->precision == 0)
			len += 2;
		else
			len += 1;
	}
	if (specs->width > len)
	{
		ft_putstr(str);
		if (specs->pound && specs->precision == 0)
			ft_putchar('.');
		ft_putpad(specs->width - len, ' ');
		return (specs->width);
	}
	ft_putstr(str);
	if (specs->pound && specs->precision == 0)
		ft_putchar('.');
	return (len);
}

int	f_output_r(t_specs *specs, char *str, char sign, int len)
{
	if (is_signed(specs, sign))
		len++;
	if (specs->pound && specs->precision == 0)
		len++;
	if (specs->width > len)
	{
		if (is_signed(specs, sign) && specs->zero)
			ft_putchar(sign);
		if (specs->zero)
			ft_putpad(specs->width - len, '0');
		else
			ft_putpad(specs->width - len, ' ');
		if (is_signed(specs, sign) && !specs->zero)
			ft_putchar(sign);
		ft_putstr(str);
		if (specs->pound && specs->precision == 0)
			ft_putchar('.');
		return (specs->width);
	}
	if (is_signed(specs, sign))
		ft_putchar(sign);
	ft_putstr(str);
	if (specs->pound && specs->precision == 0)
		ft_putchar('.');
	return (len);
}

char	*f_zero(int precision)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * precision + 3);
	if (!str)
		return (0);
	str[precision + 2] = '\0';
	while (i <= precision + 1)
	{
		str[i] = '0';
		i++;
	}
	str[1] = '.';
	return (str);
}

int	to_float(t_specs *specs, va_list argp)
{
	long double	nb;
	char		*str;
	char		sign;
	int			ret;

	if (specs->long_dbl)
		nb = va_arg(argp, long double);
	else
		nb = va_arg(argp, double);
	if (nb == 0.0 && specs->precision > 0)
		str = f_zero(specs->precision);
	else
		str = ft_ftoa(nb, specs->precision);
	sign = '+' - (specs->space * 11);
	if (nb < 0)
	{
		sign = '-';
		str = ft_memmove(str, str + 1, ft_strlen(str));
	}
	if (specs->minus)
		ret = f_output_l(specs, str, sign, ft_strlen(str));
	else
		ret = f_output_r(specs, str, sign, ft_strlen(str));
	free(str);
	return (ret);
}
