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
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		car->reg[args[1]] = car->reg[args[0]];
		return ;
	}
	args[1] = args[1] % IDX_MOD;
	args[0] = big_endian_converter(car->reg[args[0]], REG_SIZE);
	ft_memcpy(&info->memory[car->pc + args[1] % IDX_MOD],
		&args[0], REG_SIZE);
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
	args[0] = big_endian_converter(car->reg[args[0]], REG_SIZE);
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[car->pc + args[1] % IDX_MOD], REG_SIZE);
	args[2] = get_argument(info, 2, car);
	if (arg_types[2] == REG_CODE)
	{
		if (args[2] > REG_NUMBER || !args[2])
			return ;
		args[2] = car->reg[args[2]];
	}
	ft_memcpy(&info->memory[car->pc + (args[1] + args[2]) % IDX_MOD], &args[0], REG_SIZE);
}