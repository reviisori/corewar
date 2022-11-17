/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp_fork_lfork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:20 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 12:05:22 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_zjmp(t_info *info, t_car *car)
{
	car->jump = 3;
	if (car->carry)
		car->pc = (car->pc + ((short)get_argument(info, 1, car) % IDX_MOD)) % MEM_SIZE;
	else
		return ;
	car->op = info->memory[car->pc];
	if (car->op > 0x00 && car->op <= 0x10)
		car->wait = g_op[car->op][WAIT_TIME];
	else
	{
		car->jump = 1;
		car->wait = 0;
	}
}

void	op_fork(t_info *info, t_car *car)
{
	push_new_car(info, car, ((short)get_argument(info, 1, car) % IDX_MOD));
	car->jump = 3;
}

void	op_lfork(t_info *info, t_car *car)
{
	push_new_car(info, car, (short)get_argument(info, 1, car));
	car->jump = 3;
}
