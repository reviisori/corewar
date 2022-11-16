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
	unsigned int	args[2];

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	args[1] = get_argument(info, 2, car);
	if ((arg_type1 != DIR_CODE && arg_type1 != IND_CODE)
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != 0x01
		|| args[1] < 0x01 || args[1] > 0x10)
		return ;
	if (arg_type1 == DIR_CODE)
		args[0] = get_argument(info, 1, car);
	else
		args[0] = cat_n_bytes(&info->memory[((car->pc + ((short)get_argument(info, 1, car))
				% IDX_MOD) + MEM_SIZE) % MEM_SIZE], g_op[car->op][OP_DIR], info->memory);
	if (info->verbose_opts & SHOW_OP)
		ft_memcpy(car->op_args, args, sizeof(unsigned int) * sizeof(args));
	car->reg[args[1]] = args[0];
	car->carry = 0;
	if (!args[0])
		car->carry = 1;
}

/* 
	Resource VM is told to have a mistake, 
	where instead of REG_SIZE, it reads only 2 bytes.
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
		value = cat_n_bytes(&info->memory[(car->pc + (int)get_argument(info, 1, car))
				% MEM_SIZE], g_op[car->op][OP_DIR], info->memory);//Resource VM is told to have a mistake with OP_DIR == 2
	car->reg[reg] = value;
	car->carry = 0;
	if (!value)
		car->carry = 1;
}

void	op_ldi(t_info *info, t_car *car)
{
	unsigned char	arg_types[2];
	unsigned int	args[3];

	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	args[2] = get_argument(info, 3, car);
	if (!ldi_arg_validity(info, car))
		return ;
	if (arg_types[0] == REG_CODE)
		args[0] = car->reg[get_argument(info, 1, car)];
	else if (arg_types[0] == DIR_CODE)
		args[0] = get_argument(info, 1, car);
	else if (arg_types[0] == IND_CODE)
		args[0] = cat_n_bytes(&info->memory[(car->pc
					+ get_argument(info, 1, car)) % IDX_MOD], 4, info->memory);
	if (arg_types[1] == REG_CODE)
		args[1] = car->reg[get_argument(info, 2, car)];
	else if (arg_types[1] == DIR_CODE)
		args[1] = get_argument(info, 2, car);
	if (info->verbose_opts & SHOW_OP)
		ft_memcpy(car->op_args, args, sizeof(unsigned int) * sizeof(args));
	car->reg[args[2]] = cat_n_bytes(&info->memory[(car->pc + (int)(args[0] + args[1])) % IDX_MOD], 4, info->memory);
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
		value += cat_n_bytes(&info->memory[(car->pc
					+ get_argument(info, 1, car)) % IDX_MOD], 4, info->memory);
	if (arg_type2 == REG_CODE)
		value += car->reg[get_argument(info, 2, car)];
	else if (arg_type2 == DIR_CODE)
		value += get_argument(info, 2, car);
	car->reg[reg] = cat_n_bytes(&info->memory[car->pc + (int)value], 4, info->memory);
}
