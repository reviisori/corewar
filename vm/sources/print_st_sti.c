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

#define RIGHTMOST_TWO_BYTES 0xFFFF0000

void	print_st(t_car *car, unsigned int args[])
{
	print_process_id(car->index);
	ft_printf("st r%hhd %hd\n", args[0], args[1]);
}

void	print_sti(t_car *car, unsigned int args[], unsigned char arg_types[])
{
	int		sum;
	int		args_final[3];
	short	target_adr;

	ft_memcpy(args_final, args, sizeof(unsigned int) * 3);
	if (arg_types[1] == DIR_CODE && (short)args_final[1] < 0)
		args_final[1] = args_final[1] | RIGHTMOST_TWO_BYTES;
	if (arg_types[2] == DIR_CODE && (short)args_final[2] < 0)
		args_final[2] = args_final[2] | RIGHTMOST_TWO_BYTES;
	sum = args_final[1] + args_final[2];
	target_adr = car->pc + sum % IDX_MOD;
	print_process_id(car->index);
	ft_printf("sti r%hhd %d %d\n", args_final[0], args_final[1], args_final[2]);
	ft_printf("%7c| -> store to %d + %d = %d (with pc and mod %hd)\n",
		' ', args_final[1], args_final[2], sum, target_adr);
}
