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
	short	arg;

	car->jump = 3;
	if (car->carry)
	{
		arg = (short)get_argument(info, 1, car);
		car->pc = (car->pc + (arg % IDX_MOD)) % MEM_SIZE;
	}
	else
		return ;
	if (info->verbose_opts & SHOW_OP)
		car->op_args[0] = arg;
	car->op = info->memory[car->pc];
	if (car->op > 0x00 && car->op <= 0x10)
		car->wait = g_op[car->op][WAIT_TIME];
	else
		car->wait = 0;
}

void	op_fork(t_info *info, t_car *car)
{
	short	arg;

	arg = (short)get_argument(info, 1, car);
	push_new_car(info, car, (arg % IDX_MOD));
	if (info->verbose_opts & SHOW_OP)
		car->op_args[0] = arg;
	car->jump = 3;
}

void	op_lfork(t_info *info, t_car *car)
{
	short	arg;

	arg = (short)get_argument(info, 1, car);
	push_new_car(info, car, arg);
	if (info->verbose_opts & SHOW_OP)
		car->op_args[0] = arg;
	car->jump = 3;
}
