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
		{
			if (info->verbose_opts & SHOW_DEATH && car->alive)
				ft_printf("Process %u hasn't lived for %i cycles (CTD %i)\n",
					car->index, info->cycle - car->last_live, info->cycles_to_die);	
			car->alive = 0;
		}
		car = car->next;
	}
	info->checks_after_mod++;
	if (info->lives_this_check >= NBR_LIVE
		|| info->checks_after_mod >= MAX_CHECKS)
	{
		info->cycles_to_die -= CYCLE_DELTA;
		info->checks_after_mod = 0;
		if (info->verbose_opts & SHOW_CYCLE)
			ft_printf("Cycle to die is now %i\n", info->cycles_to_die);
	}
	info->next_check_cycle = info->cycle + info->cycles_to_die;
	info->lives_this_check = 0;
}
