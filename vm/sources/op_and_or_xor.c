/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_or_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:03:18 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:03:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_and(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	args[0] = get_argument(info, 1, car);
	if (arg_types[0] == REG_CODE)
	{
		if (args[0] > REG_NUMBER || !args[0])
			return ;
		args[0] = car->reg[args[0]];
	}
	else if (arg_types[0] == IND_CODE)
		args[0] = cat_n_bytes(&info->memory[car->pc + args[0] % IDX_MOD], REG_SIZE);
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[car->pc + args[1] % IDX_MOD], REG_SIZE);
	args[2] = get_argument(info, 3, car);
	if (args[2] > REG_NUMBER || !args[2])
		return ;
	car->reg[args[2]] = args[0] & args[1];
	if (!car->reg[args[2]])
		car->carry = 1;
	else
		car->carry = 0;
}

void	op_or(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	args[0] = get_argument(info, 1, car);
	if (arg_types[0] == REG_CODE)
	{
		if (args[0] > REG_NUMBER || !args[0])
			return ;
		args[0] = car->reg[args[0]];
	}
	else if (arg_types[0] == IND_CODE)
		args[0] = cat_n_bytes(&info->memory[car->pc + args[0] % IDX_MOD], REG_SIZE);
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[car->pc + args[1] % IDX_MOD], REG_SIZE);
	args[2] = get_argument(info, 3, car);
	if (args[2] > REG_NUMBER || !args[2])
		return ;
	car->reg[args[2]] = args[0] | args[1];
	if (!car->reg[args[2]])
		car->carry = 1;
	else
		car->carry = 0;
}

void	op_xor(t_info *info, t_car *car)
{
	unsigned char	arg_types[3];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	arg_types[2] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3);
	if (!arg_types[0] || !arg_types[1] || arg_types[2] != REG_CODE)
		return ;
	args[0] = get_argument(info, 1, car);
	if (arg_types[0] == REG_CODE)
	{
		if (args[0] > REG_NUMBER || !args[0])
			return ;
		args[0] = car->reg[args[0]];
	}
	else if (arg_types[0] == IND_CODE)
		args[0] = cat_n_bytes(&info->memory[car->pc + args[0] % IDX_MOD], REG_SIZE);
	args[1] = get_argument(info, 2, car);
	if (arg_types[1] == REG_CODE)
	{
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		args[1] = car->reg[args[1]];
	}
	else if (arg_types[1] == IND_CODE)
		args[1] = cat_n_bytes(&info->memory[car->pc + args[1] % IDX_MOD], REG_SIZE);
	args[2] = get_argument(info, 3, car);
	if (args[2] > REG_NUMBER || !args[2])
		return ;
	car->reg[args[2]] = args[0] ^ args[1];
	if (!car->reg[args[2]])
		car->carry = 1;
	else
		car->carry = 0;
}