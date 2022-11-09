/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:45:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/08 12:45:55 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_st(t_info *info, t_car *car)
{
	unsigned char	arg_type;
	unsigned char	arg1;
	unsigned char	arg2;

	arg_type = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	if (arg_type != REG_CODE)
		return ;
	arg1 = info->memory[(car->pc + 2) % MEM_SIZE];
	if (arg1 > 0x10 || !arg1)
		return ;
	arg_type = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	if (arg_type != REG_CODE && arg_type != IND_CODE)
		return ;
	if (arg_type == REG_CODE)
	{
		arg2 = info->memory[(car->pc + 3) % MEM_SIZE];
		if (arg2 > 0x10 || !arg2)
			return ;
		car->reg[arg2] = car->reg[arg1];
		return ;
	}
	arg2 = (info->memory[(car->pc + 3) % MEM_SIZE] << 2) + \
		info->memory[(car->pc + 4) % MEM_SIZE];
	ft_memcpy(&info->memory[(car->pc + arg2) % MEM_SIZE], &car->reg[arg1], REG_SIZE);
}
