/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:59:35 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/09 11:59:38 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_live(t_info *info, t_car *car)
{
	unsigned int	arg;

	car->jump = 1 + REG_SIZE;
	car->last_live = info->cycle;
	info->lives_this_check++;
	arg = cat_n_bytes(&info->memory[car->pc + 1], REG_SIZE);
	if ((0x00 - arg) <= (unsigned int)info->champion_count)
		info->champions[0x00 - arg - 1].last_live = info->cycle;
}

void	op_aff(t_info *info, t_car *car)
{
	(void)info;
	(void)car;
}
