/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zjmp_fork_lfork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:36 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:52:37 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_zjmp(t_car *car, unsigned int arg, bool success)
{
	ft_printf("P%5d | ", car->index);
	if (success)
		ft_printf("zjmp %hd OK\n", arg);
	if (!success)
		ft_printf("zjmp %hd FAILED\n", arg);
}

void	print_fork(t_car *car, unsigned int arg)
{
	short	adr;

	ft_printf("P%5d | ", car->index);
	adr = car->pc + (short)arg % IDX_MOD % MEM_SIZE;
	ft_printf("fork %hd (%hd)\n", arg, adr);
}

void	print_lfork(t_car *car, unsigned int arg)
{
	short	adr;

	ft_printf("P%5d | ", car->index);
	adr = (car->pc + arg) % MEM_SIZE;
	ft_printf("lfork %hd (%hd)\n", arg, adr);
}
