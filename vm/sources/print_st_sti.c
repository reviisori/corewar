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

void	print_sti(t_car *car, unsigned int args[], unsigned char arg_types[])
{
	int		sum;
	short	target_adr;

	ft_printf("P%5d | ", car->index);
	ft_printf("sti r%hhd ", args[0]);
	if (arg_types[1] == DIR_CODE)
		ft_printf("%hd ", args[1]);
	else
		ft_printf("%d ", args[1]);
	if (arg_types[2] == DIR_CODE)
		ft_printf("%hd\n", args[2]);
	else
		ft_printf("%d\n", args[2]);
	sum = args[1] + args[2];
	target_adr = (car->pc + ((short)sum % IDX_MOD));
	ft_printf("%7c| -> store to ", ' ');
	if (arg_types[1] == DIR_CODE)
		ft_printf("%hd + ", args[1]);
	else
		ft_printf("%d + ", args[1]);
	if (arg_types[2] == DIR_CODE)
		ft_printf("%hd = ", args[2]);
	else
		ft_printf("%d = ", args[2]);
	if (arg_types[1] == DIR_CODE && arg_types[2] == DIR_CODE)
		ft_printf("%hd ", sum);
	else
		ft_printf("%d ", sum);
	ft_printf("(with pc and mod %hd)\n", target_adr);
}
