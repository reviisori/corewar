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
	if (car->carry)
		car->pc = (get_argument(info, 1, car) % IDX_MOD);
	car->jump = 3;
}

void	op_fork(t_info *info, t_car *car)
{
	push_new_car(info, car, (get_argument(info, 1, car) % IDX_MOD));
	car->jump = 3;
}

void	op_lfork(t_info *info, t_car *car)
{
	push_new_car(info, car, get_argument(info, 1, car));
	car->jump = 3;
}
