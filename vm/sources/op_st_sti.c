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
	unsigned char	args[2];
	unsigned char	reg_bytes[4];
	unsigned int	be_reg_content;

	ft_bzero(reg_bytes, REG_SIZE);
	arg_types[0] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 1);
	arg_types[1] = get_crumb(info->memory[(car->pc + 1) % MEM_SIZE], 2);
	if (arg_types[0] != REG_CODE
		|| (arg_types[1] != REG_CODE && arg_types[1] != IND_CODE))
		return ;
	args[0] = info->memory[(car->pc + 2) % MEM_SIZE];
	if (args[0] > REG_NUMBER || !args[0])
		return ;
	if (arg_types[1] == REG_CODE)
	{
		args[1] = info->memory[(car->pc + 3) % MEM_SIZE];
		if (args[1] > REG_NUMBER || !args[1])
			return ;
		car->reg[args[1]] = car->reg[args[0]];
		return ;
	}
	args[1] = (info->memory[(car->pc + 3) % MEM_SIZE] << 2) + \
		info->memory[(car->pc + 4) % MEM_SIZE];
	ft_memcpy(reg_bytes, &car->reg[args[0]], REG_SIZE);
	be_reg_content = big_endian_converter(reg_bytes, REG_SIZE);
	ft_memcpy(&info->memory[(car->pc + args[1] % IDX_MOD) % MEM_SIZE],
		&be_reg_content, REG_SIZE);
}

void	op_sti(t_info *info, t_car *car)
{
	(void)info;
	(void)car;
}
