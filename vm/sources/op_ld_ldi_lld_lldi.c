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

void	op_ld(t_info *info, t_car *car)
{
	unsigned char	arg_type1;
	unsigned int	reg;
	unsigned int	value;

	arg_type1 = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	reg = get_argument(info, 2, car);
	if ((arg_type1 != DIR_CODE && arg_type1 != IND_CODE) 
		|| get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2) != 0x01
		||  reg < 0x01 || reg > 0x10)
		return ;
	if (arg_type1 == DIR_CODE)
		value = get_argument(info, 1, car);
	else
		value = cat_n_bytes(&info->memory[(car->pc + get_argument(info, 1, car))
			% MEM_SIZE], REG_SIZE);
	car->reg[reg] = value % IDX_MOD;
	car->carry = 0;
	if (!value)
		car->carry = 1;
}

void	op_ldi(t_info *info, t_car *car)
{
	(void)info;
	(void)car;
}

/* 
	Resource VM is told to have a mistake, where instead of REG_SIZE, it reads only 2 bytes.
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
		||  reg < 0x01 || reg > 0x10)
		return ;
	if (arg_type1 == DIR_CODE)
		value = get_argument(info, 1, car);
	else
		value = cat_n_bytes(&info->memory[(car->pc + get_argument(info, 1, car))
			% MEM_SIZE], REG_SIZE);//Resource VM is told to have a mistake, where instead of REG_SIZE it uses 2
	car->reg[reg] = value;
	car->carry = 0;
	if (!value)
		car->carry = 1;
}

void	op_lldi(t_info *info, t_car *car)
{
	(void)info;
	(void)car;
}
