/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld_ldi_lld_lldi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:08:30 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:08:31 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ldi_arg_validity(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned char	arg_type2;
	unsigned int	reg;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_type2 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	reg = get_argument(info, 3, car);
	if (!arg_type1 || (arg_type2 != DIR_CODE && arg_type2 != REG_CODE)
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 3) != REG_CODE
		|| reg < 0x01 || reg > 0x10 || (arg_type1 == REG_CODE
			&& (get_argument(info, 1, car) < 0x01
				|| get_argument(info, 1, car) > 0x10))
		|| (arg_type2 == REG_CODE
			&& (get_argument(info, 2, car) < 0x01
				|| get_argument(info, 2, car) > 0x10)))
		return (0);
	return (1);
}

void	op_ld(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned int	reg;
	unsigned int	value;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	reg = get_argument(info, 2, car);
	if ((arg_type1 != DIR_CODE && arg_type1 != IND_CODE)
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != 0x01
		|| reg < 0x01 || reg > 0x10)
		return ;
	if (arg_type1 == DIR_CODE)
		value = get_argument(info, 1, car);
	else
		value = cat_n_bytes(&info->memory[((car->pc + ((short)get_argument(info, 1, car))
				% IDX_MOD) + MEM_SIZE) % MEM_SIZE], g_op[car->op][OP_DIR], info->memory);
	car->reg[reg] = value;
	car->carry = 0;
	if (!value)
		car->carry = 1;
}

/* 
	Resource VM is told to have a mistake, where instead of REG_SIZE, it reads
	only 2 bytes when given an indirect argument. It also doesn't always write
	the correct value to the registry even compared to those read two bytes...
 */
void	op_lld(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned int	reg;
	unsigned int	value;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	reg = get_argument(info, 2, car);
	if ((arg_type1 != DIR_CODE && arg_type1 != IND_CODE)
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != 0x01
		|| reg < 0x01 || reg > 0x10)
		return ;
	if (arg_type1 == DIR_CODE)
		value = get_argument(info, 1, car);
	else
		value = cat_n_bytes(&info->memory[(car->pc + ((short)get_argument(info, 1, car))
			+ MEM_SIZE) % MEM_SIZE], g_op[car->op][OP_DIR], info->memory);
	car->reg[reg] = value;
	car->carry = 0;
	if (!value)
		car->carry = 1;
}

void	op_ldi(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned char	arg_type2;
	unsigned int	reg;
	unsigned int	value;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_type2 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	reg = get_argument(info, 3, car);
	if (!ldi_arg_validity(info, car))
		return ;
	value = 0;
	if (arg_type1 == REG_CODE)
		value += car->reg[get_argument(info, 1, car)];
	else if (arg_type1 == DIR_CODE)
		value += get_argument(info, 1, car);
	else if (arg_type1 == IND_CODE)
		value += cat_n_bytes(&info->memory[((car->pc + ((short)get_argument(info, 1, car))
				% IDX_MOD) + MEM_SIZE) % MEM_SIZE], 4, info->memory);
	if (arg_type2 == REG_CODE)
		value += car->reg[get_argument(info, 2, car)];
	else if (arg_type2 == DIR_CODE)
		value += get_argument(info, 2, car);
	car->reg[reg] = cat_n_bytes(&info->memory[((car->pc + (short)value) % IDX_MOD + MEM_SIZE) % MEM_SIZE], 4, info->memory);
}

void	op_lldi(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned char	arg_type2;
	unsigned int	reg;
	unsigned int	value;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_type2 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	reg = get_argument(info, 3, car);
	if (!ldi_arg_validity(info, car))
		return ;
	value = 0;
	if (arg_type1 == REG_CODE)
		value += car->reg[get_argument(info, 1, car)];
	else if (arg_type1 == DIR_CODE)
		value += get_argument(info, 1, car);
	else if (arg_type1 == IND_CODE)
		value += cat_n_bytes(&info->memory[(car->pc + (short)get_argument(info, 1, car)
			+ MEM_SIZE) % MEM_SIZE], 4, info->memory);
	if (arg_type2 == REG_CODE)
		value += car->reg[get_argument(info, 2, car)];
	else if (arg_type2 == DIR_CODE)
		value += get_argument(info, 2, car);
	car->reg[reg] = cat_n_bytes(&info->memory[((car->pc + (short)value) + MEM_SIZE) % MEM_SIZE], 4, info->memory);
}