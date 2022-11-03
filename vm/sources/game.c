/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:39:37 by mapostol          #+#    #+#             */
/*   Updated: 2022/11/03 13:39:39 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_kill(char *reason)
{
	if (reason)
		write(2, reason, ft_strlen(reason));
	write(2, "error\n", 6);
	exit(0);
}

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

int	declare_winner(t_info *info)
{
	info++;
	info--;
	return (1);
}

void	run_all_cars(t_info *info)
{
	info++;
	info--;
}

void	check_aliveness(t_info *info)
{
	t_car	*car;

	car = info->liststart;
	while (car)
	{
		if (info->cycle - info->cycle_to_die >= car->last_live)
			car->alive = 0;
		car = car->next;
	}
}

void	copy_parent_reg(t_car *dest, t_car *parent)
{
	int	i;

	i = 1;
	while (i <= REG_NUMBER + 1)
	{
		dest->reg[i] = parent->reg[i];
		i++;
	}
}

void	init_car(t_car *car, t_info *info, t_car *parent, int forkjump)
{
	if (!info->liststart)
		car->index = 1;
	else
		car->index = info->liststart->index + 1;
	ft_bzero(car->reg, REG_SIZE * (REG_NUMBER + 1));
	if (!parent)
	{
		car->reg[1] = MAX_UINT - car->index + 1;
		car->pc = ((MEM_SIZE / info->champion_count) * (info->champion_count - car->index)) % MEM_SIZE;
	}
	else
	{
		copy_parent_reg(car, parent);
		car->pc = (parent->pc + forkjump) % MEM_SIZE;
	}
	car->carry = 0;
	car->op = info->memory[car->pc];
	car->last_live = 0;
/* 	if (car->op > 0 && car->op < 0x11) *///needs to get these from the table
		car->wait = 0;//temp
/* 	if (car->op > 0 && car->op < 0x11) *///needs to get these from the table
		car->jump = 1;//temp 
	car->alive = 1;
}

void	push_new_car(t_info *info, t_car *parent, int forkjump)
{
	t_car	*fresh;

	fresh = (t_car *) malloc(sizeof(t_car));
	if (!fresh)
		error_kill("malloc ");
	init_car(fresh, info, parent, forkjump);
	fresh->next = info->liststart;
	info->liststart = fresh;
}

void	init_pregame_cars(t_info *info)
{
	int		players;

	if (info->champion_count < 1 || info->champion_count > MAX_PLAYERS)//redundant
		error_kill("champion amount ");//redundant
	players = info->champion_count;
	info->liststart = NULL;
	while (players > 0)
	{
		push_new_car(info, NULL, 0);
		players--;
	}
}

void	init_vars(t_info *info)
{
	info->cycle = 1;// or 0?
	info->cycle_to_die = CYCLE_TO_DIE;
	info->next_check_cycle = CYCLE_TO_DIE;
}

int	run_game(t_info *info)
{
	init_vars(info);
	init_pregame_cars(info);//allocate + initialize
	while (1)// one cycle
	{
		if (no_cars_alive(info))
			return (declare_winner(info));
		run_all_cars(info);
		if (info->cycle == info->next_check_cycle || info->cycle_to_die < 1)
			check_aliveness(info);
/* 		if (info->cycle == info->dump_cycles)
			return (dump()); */
		info->cycle++;
	}

}