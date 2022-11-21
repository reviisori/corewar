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

#define RIGHTMOST_TWO_BYTES 0xFFFF0000

void	print_ld(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("ld %d r%hhd\n", args[0], args[1]);
}

void	print_ldi(t_car *car, unsigned int args[], unsigned char arg_types[])
{
	int		sum;
	int		args_final[3];
	short	target_adr;

	ft_memcpy(args_final, args, sizeof(unsigned int) * 3);
	if (arg_types[0] == DIR_CODE && (short)args_final[0] < 0)
		args_final[0] = args_final[0] | RIGHTMOST_TWO_BYTES;
	if (arg_types[1] == DIR_CODE && (short)args_final[1] < 0)
		args_final[1] = args_final[1] | RIGHTMOST_TWO_BYTES;
	sum = args_final[0] + args_final[1];
	target_adr = car->pc + sum % IDX_MOD;
	print_process_id(car->index);
	ft_printf("ldi %d %d r%hhd\n", args_final[0], args_final[1], args_final[2]);
	ft_printf("%7c| -> load from %d + %d = %d (with pc and mod %hd)\n",
		' ', args_final[0], args_final[1], sum, target_adr);
}

void	print_lld(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("lld %d r%hhd\n", args[0], args[1]);
}

void	print_lldi(t_car *car, unsigned int args[])
{
	int				sum;
	unsigned int	with_pc;

	print_process_id(car->index);
	ft_printf("lldi %d ", args[0]);
	ft_printf("%d ", args[1]);
	ft_printf("r%hhd\n", args[2]);
	sum = args[0] + args[1];
	with_pc = car->pc + sum;
	ft_printf("%7c| -> load from %d + %d = %d (with pc %u)\n",
		' ',
		args[0],
		args[1],
		sum,
		with_pc);
}
