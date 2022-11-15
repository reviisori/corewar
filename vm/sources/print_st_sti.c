/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:01:44 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 13:01:46 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_st(t_car *car)
{
	if (car->op_arg_types[1] == IND_CODE)
		ft_printf("st r%hhd %hd\n", car->op_args[0], car->op_args[1]);
	else
		ft_printf("st r%hhd r%hhd\n", car->op_args[0], car->op_args[1]);
}

void	print_sti(t_car *car) //continue!!!
{
	ft_printf("sti r%hhd ", car->op_args[0]);
	if (car->op_arg_types[1] == DIR_CODE)
		ft_printf("%d ", car->op_args[1]);
	else if (car->op_arg_types[1] == REG_CODE)
		ft_printf("r%hhd ", car->op_args[1]);
	else
		ft_printf("%hd ", (short)car->op_args[1]);
	if (car->op_arg_types[2] == REG_CODE)
		ft_printf("r%hhd\n", car->op_args[2]);
	else
		ft_printf("%d\n", car->op_args[2]);
}
