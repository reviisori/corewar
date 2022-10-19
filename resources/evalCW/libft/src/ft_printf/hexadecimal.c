/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:29:59 by rkyttala          #+#    #+#             */
/*   Updated: 2021/05/24 18:38:33 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	x_output_l(t_specs *specs, char *str, int len, char *pref)
{
	if (specs->precision == -1)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putstr(str);
		ft_putpad(specs->width - (specs->pound * 2 + len), ' ');
		return (specs->width);
	}
	if (specs->pound)
		ft_putstr(pref);
	if (specs->precision > len)
		ft_putpad(specs->precision - len, '0');
	ft_putstr(str);
	if (specs->precision > len)
		ft_putpad(specs->width - specs->precision - (specs->pound * 2), ' ');
	else
		ft_putpad(specs->width - len - (specs->pound * 2), ' ');
	if (specs->width >= specs->precision + (specs->pound * 2))
		return (specs->width);
	else
		return (specs->precision + (specs->pound * 2));
}

int	x_output_r(t_specs *specs, char *str, int len, char *pref)
{
	if (specs->zero && specs->precision == -1)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putpad(specs->width - (specs->pound * 2 + len), '0');
		ft_putstr(str);
		return (specs->width);
	}
	if (specs->precision > len)
		ft_putpad(specs->width - specs->precision - (specs->pound * 2), ' ');
	else
		ft_putpad(specs->width - len - (specs->pound * 2), ' ');
	if (specs->pound)
		ft_putstr(pref);
	if (specs->precision > len)
		ft_putpad(specs->precision - len, '0');
	ft_putstr(str);
	if (specs->width >= specs->precision + (specs->pound * 2))
		return (specs->width);
	else
		return (specs->precision + (specs->pound * 2));
}

int	x_output(t_specs *specs, char *str, int len, char *pref)
{
	int	ret;

	if (specs->precision > len)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		if (specs->pound)
			ret = specs->precision + 2;
		else
			ret = specs->precision;
	}
	else
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putstr(str);
		if (specs->pound)
			ret = len + 2;
		else
			ret = len;
	}
	return (ret);
}

int	to_hex(t_specs *specs, va_list argp, int upper)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	char				*prefix;
	int					ret;

	nb = oux_length(specs, argp);
	if (!nb)
		return (oux_zeroprecision(specs));
	if (upper)
		prefix = ft_strdup("0X");
	else
		prefix = ft_strdup("0x");
	str = ft_itoa_base(nb, 16, upper);
	len = ft_strlen(str);
	if (specs->width > len && specs->width > specs->precision && !specs->minus)
		ret = x_output_r(specs, str, len, prefix);
	else if (specs->width > len && specs->width > specs->precision \
		&& specs->minus)
		ret = x_output_l(specs, str, len, prefix);
	else
		ret = x_output(specs, str, len, prefix);
	free(prefix);
	free(str);
	return (ret);
}
