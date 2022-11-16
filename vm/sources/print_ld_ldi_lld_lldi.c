/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld_ldi_lld_lldi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:08 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:52:09 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_ld(t_car *car)
{
	ft_printf("ld %d r%hhd\n", car->op_args[0], car->op_args[1]);
}

void	print_ldi(t_car *car)
{
	int				sum;
	unsigned short	target_adr;

	ft_printf("ldi %d ", car->op_args[0]);
	ft_printf("%d ", car->op_args[1]);
	ft_printf("r%hhd\n", car->op_args[2]);
	sum = car->op_args[0] + car->op_args[1];
	target_adr = (car->pc + (short)(sum % IDX_MOD)) % MEM_SIZE;
	ft_printf("%7c| -> load from %d + %d = %d (with pc and mod %hu)\n",
		' ',
		car->op_args[0],
		car->op_args[1],
		sum,
		target_adr);
}

void	print_lld(t_car *car)
{
	ft_printf("ld %d r%hhd\n", car->op_args[0], car->op_args[1]);
}

void	print_lldi(t_car *car)
{
		int				sum;
	unsigned short	target_adr;

	ft_printf("ldi %d ", car->op_args[0]);
	ft_printf("%d ", car->op_args[1]);
	ft_printf("r%hhd\n", car->op_args[2]);
	sum = car->op_args[0] + car->op_args[1];
	target_adr = (car->pc + (short)sum) % MEM_SIZE;
	ft_printf("%7c| -> load from %d + %d = %d (with pc and mod %hu)\n",
		' ',
		car->op_args[0],
		car->op_args[1],
		sum,
		target_adr);
}
