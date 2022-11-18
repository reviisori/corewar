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
#include "operations.h"

void	error_kill(char *reason)
{
	if (reason)
		write(2, reason, ft_strlen(reason));
	write(2, "error\n", 6);
	exit(0);
}

int	calculate_jump(unsigned char c_byte, unsigned char op)
{
	unsigned char	store;
	int				i;
	int				sum;

 	if (op < 1 || op > 0x10)
		return (1);
	if (!c_byte)
		return (2);
	i = 3;
	sum = 0;
	store = c_byte;
	while (i >= 0)
	{
		c_byte = store;
		c_byte = c_byte >> (2 * i);
		if (!g_arg_types[op][CRUMBS_IN_BYTE - i - 1])
			break;
/* 		if ((g_arg_types[op][CRUMBS_IN_BYTE - i - 1] & c_byte) != 0)
		{ */
			sum += cast_arg_type_to_bytes(c_byte, op);
			store -= c_byte << (2 * i);
/* 		}
		else
			return (1); */
		i--;
	}
	return (sum + 1 + g_op[op][C_BYTE]);
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
	//ft_printf("Last cycle: %u", info->cycle);//
	return (1);
}

int	jump_and_refresh(t_car *car, t_info *info)
{
	car->pc = (car->pc + car->jump) % MEM_SIZE;
	car->op = info->memory[car->pc];
	if (car->op < 1 || car->op > 0x10)
		return (0);
	car->wait = g_op[car->op][WAIT_TIME];
	return (1);
}

void	execute_op(t_car *car, t_info *info)
{
	if (car->op > 0 && car->op < 0x11)
	{
		if (g_op[car->op][C_BYTE])
			car->jump = calculate_jump(info->memory[(car->pc + 1) % MEM_SIZE], car->op);
		g_op_jump_table[car->op](info, car);
	}
	else
		car->jump = 1;
/*  	ft_printf("\nCycle %i, car %u ran the operation %x\n", info->cycle, car->index, car->op);//
	ft_printf("Its PC is %u, and jump %i.\n", car->pc, car->jump);// */
}

void	run_all_cars(t_info *info)
{
	t_car	*car;
	int		flag;//kinda redundant, for the theoretical case of some op having wait time 1

	car = info->liststart;
	while (car)
	{
		if (!car->alive)
		{
			car = car->next;
			continue ;
		}
		flag = 1;
		if (car->wait == 0)
			flag = jump_and_refresh(car, info);
		if (flag)
			car->wait--;
		if (car->wait == 0)
			execute_op(car, info);
		car = car->next;
	}
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
		car->pc = ((MEM_SIZE / info->champion_count)
				* (car->index - 1)) % MEM_SIZE;
		car->last_live = 0;
		car->carry = 0;
	}
	else
	{
		copy_parent_reg(car, parent);
		car->pc = (parent->pc + forkjump) % MEM_SIZE;
		car->last_live = parent->last_live;
		car->carry = parent->carry;
	}
	car->op = info->memory[car->pc];
	car->wait = 0;//might be an issue, if op happens to change between this cycle and next. Which one is correct?
	car->jump = 0;
 	if (car->op > 0 && car->op < 0x11)
		car->wait = g_op[car->op][WAIT_TIME];
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
	info->cycle = 1;//or 0?
	info->cycles_to_die = CYCLE_TO_DIE;
	info->next_check_cycle = CYCLE_TO_DIE;
	info->lives_this_check = 0;
	info->checks_after_mod = 0;
}

static void    print_memory(unsigned char memory[])
{
    int                i;
    int                line_len;
    unsigned int    line_count;

    line_len = 64;
    line_count = 0;
    i = -1;
    while (++i < MEM_SIZE)
    {
        if (i % line_len == 0)
            ft_printf("0x%04x : ", line_len * line_count++);
        ft_printf("%02x ", memory[i]);
        if ((i + 1) % line_len == 0)
            ft_putchar('\n');
    }
    exit(0);
}

int	run_game(t_info *info)
{
	init_vars(info);
	init_pregame_cars(info);//allocate + initialize
	if (!info->dump_cycles)
		print_memory(info->memory);
	while (1) // one cycle
	{
		if (no_cars_alive(info))
			return (declare_winner(info));
		run_all_cars(info);
		if (info->cycle == info->next_check_cycle || info->cycles_to_die < 1)
			check_aliveness(info);
		if ((int)info->cycle == info->dump_cycles)
			print_memory(info->memory);
		info->cycle++;
	}
}
