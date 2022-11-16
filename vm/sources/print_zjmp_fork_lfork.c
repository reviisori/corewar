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

void	print_zjmp(t_car *car)
{
	ft_printf("zjmp %hd OK\n", car->op_args[0]);
}

void	print_fork(t_car *car)
{
	short	adr;

	adr = (car->pc + car->op_args[0] % IDX_MOD) % MEM_SIZE;
	ft_printf("fork %hd (%hd)\n", car->op_args[0], adr);
}

void	print_lfork(t_car *car)
{
	short	adr;

	adr = (car->pc + car->op_args[0]) % MEM_SIZE;
	ft_printf("fork %hd (%hd)\n", car->op_args[0], adr);
}
