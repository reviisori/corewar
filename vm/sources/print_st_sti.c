/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:01:44 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 13:01:46 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_st(t_car *car)
{
	ft_printf("st r%hhd %hd\n", car->op_args[0], car->op_args[1]);
}

void	print_sti(t_car *car)
{
	int				sum;
	unsigned short	target_adr;

	ft_printf("sti r%hhd ", car->op_args[0]);
	ft_printf("%d ", car->op_args[1]);
	ft_printf("%d\n", car->op_args[2]);
	sum = car->op_args[1] + car->op_args[2];
	target_adr = (car->pc + (short)(sum % IDX_MOD)) % MEM_SIZE;
	ft_printf("%7c| -> store to %d + %d = %d (with pc and mod %hu)\n",
		' ',
		car->op_args[1],
		car->op_args[2],
		sum,
		target_adr);
}
