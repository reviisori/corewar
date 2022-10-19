/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:32:40 by rkyttala          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:15 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long	oux_length(t_specs *specs, va_list argp)
{
	unsigned long long	nb;

	if (specs->h)
		nb = (unsigned short)(va_arg(argp, unsigned int));
	else if (specs->hh)
		nb = (unsigned char)(va_arg(argp, unsigned int));
	else if (specs->l)
		nb = va_arg(argp, unsigned long);
	else if (specs->ll)
		nb = va_arg(argp, unsigned long long);
	else
		nb = va_arg(argp, unsigned int);
	return (nb);
}

long long	di_length(t_specs *specs, va_list argp)
{
	long long int	nb;

	if (specs->h)
		nb = (short)(va_arg(argp, int));
	else if (specs->hh)
		nb = (char)(va_arg(argp, int));
	else if (specs->l)
		nb = va_arg(argp, long);
	else if (specs->ll)
		nb = va_arg(argp, long long);
	else
		nb = va_arg(argp, int);
	return (nb);
}

int	x_zerop(t_specs *specs)
{
	if (specs->minus)
	{
		if (specs->precision > 1)
			ft_putpad(specs->precision, '0');
		else
			ft_putchar('0');
	}
	if (specs->precision == -1)
		ft_putpad(specs->width - 1, ' ' + (specs->zero * 16));
	else
		ft_putpad(specs->width - specs->precision, ' ' + (specs->zero * 16));
	if (!specs->minus)
	{
		if (specs->precision > 1)
			ft_putpad(specs->precision, '0');
		else
			ft_putchar('0');
	}
	if (specs->precision > specs->width)
		return (specs->precision);
	if (specs->width > 1)
		return (specs->width);
	else
		return (1);
}

int	oux_zeroprecision(t_specs *specs)
{
	if (specs->pound && specs->type == 'o')
	{
		if (specs->minus)
			ft_putchar('0');
		ft_putpad(specs->width - 1, ' ');
		if (!specs->minus)
			ft_putchar('0');
		if (specs->width > 0)
			return (specs->width);
		else
			return (1);
	}
	if ((specs->type == 'x' || specs->type == 'X') && specs->precision != 0)
		return (x_zerop(specs));
	ft_putpad(specs->width, ' ');
	return (specs->width);
}

int	print_percent(t_specs *specs)
{
	if (specs->width > 1)
	{
		if (specs->minus)
			ft_putchar('%');
		if (specs->zero)
			ft_putpad(specs->width - 1, '0');
		else
			ft_putpad(specs->width - 1, ' ');
		if (!specs->minus)
			ft_putchar('%');
		return (specs->width);
	}
	ft_putchar('%');
	return (1);
}
