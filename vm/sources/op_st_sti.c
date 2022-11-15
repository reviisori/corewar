/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:23 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:07:25 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define RIGHTMOST_BYTE 0xFF000000

static void	save_args(t_car *car, unsigned char arg_t[],
	unsigned int args[], int count)
{
	ft_memcpy(car->op_arg_types, arg_t, sizeof(unsigned char) * count);
	ft_memcpy(car->op_args, args, sizeof(unsigned int) * count);
}

static void	copy_to_memory(unsigned char memory[], unsigned int adr,
	unsigned int value)
{
	int				byte_count;
	unsigned int	byte;

	byte_count = -1;
	while (++byte_count < REG_SIZE)
	{
		byte = value << BITS_IN_BYTE * byte_count & RIGHTMOST_BYTE;
		byte = byte >> (REG_SIZE - 1) * BITS_IN_BYTE;
		memory[adr % MEM_SIZE] = byte;
		adr++;
	}
}

void	op_st(t_info *info, t_car *car)
{
	unsigned char	arg_types[2];
	unsigned int	args[2];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	if (arg_types[0] != REG_CODE
		|| (arg_types[1] != REG_CODE && arg_types[1] != IND_CODE))
		return ;
	args[0] = get_argument(info, 1, car);
	if (args[0] > REG_NUMBER || !args[0])
		return ;
	args[1] = get_argument(info, 2, car);
	if (info->verbose_opts & SHOW_OP)
		save_args(car, arg_types, args, 2);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		car->reg[args[1]] = car->reg[args[0]];
		return ;
	}
	args[0] = car->reg[args[0]];
	copy_to_memory(info->memory, car->pc + ((short)args[1] % IDX_MOD), args[0]);
}

void	op_sti(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (arg_types[0] != REG_CODE || !arg_types[1]
		|| (arg_types[2] != REG_CODE && arg_types[2] != DIR_CODE))
		return ;
	args[0] = get_argument(info, 1, car);
	if (args[0] > REG_NUMBER || !args[0])
		return ;
	args[1] = get_argument(info, 2, car);
	args[2] = get_argument(info, 3, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[car->pc + args[1] % IDX_MOD], REG_SIZE, info->memory);
	if (arg_types[2] == REG_CODE)
	{
		if (args[2] > REG_NUMBER || !args[2])
			return ;
		args[2] = car->reg[args[2]];
	}
	if (info->verbose_opts & SHOW_OP)
		save_args(car, arg_types, args, 3);
	args[0] = car->reg[args[0]];
	copy_to_memory(info->memory, car->pc + ((int)(args[1] + args[2]) % IDX_MOD), args[0]);
}
