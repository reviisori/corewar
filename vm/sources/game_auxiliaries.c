/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_auxiliaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/18 11:40:39 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	no_cars_alive(t_info *info)
{
	t_car	*car;

	car = info->liststart;
	while (car)
	{
		if (car->alive)
			return (0);
		car = car->next;
	}
	return (1);
}

void	check_aliveness(t_info *info)
{
	t_car	*car;

	car = info->liststart;
	while (car)
	{
		if (info->cycles_to_die < 1
			|| info->cycle - info->cycles_to_die >= car->last_live)
			car->alive = 0;
		car = car->next;
	}
	info->checks_after_mod++;
	if (info->lives_this_check >= NBR_LIVE
		|| info->checks_after_mod >= MAX_CHECKS)
	{
		info->cycles_to_die -= CYCLE_DELTA;
		info->checks_after_mod = 0;
	}
	info->next_check_cycle = info->cycle + info->cycles_to_die;
	info->lives_this_check = 0;
}
