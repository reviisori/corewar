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

void	print_st(t_car *car, unsigned int args[])
{
	ft_printf("P%5d | ", car->index);
	ft_printf("st r%hhd %hd\n", args[0], args[1]);
}

void	print_sti(t_car *car, unsigned int args[])
{
	int				sum;
	short	target_adr;

	ft_printf("P%5d | ", car->index);
	ft_printf("sti r%hhd ", args[0]);
	ft_printf("%d ", args[1]);
	ft_printf("%d\n", args[2]);
	sum = args[1] + args[2];
	target_adr = (car->pc + ((short)sum % IDX_MOD)) % MEM_SIZE;
	ft_printf("%7c| -> store to %d + %d = %d (with pc and mod %hu)\n",
		' ',
		args[1],
		args[2],
		sum,
		target_adr);
}
