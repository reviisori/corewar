/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_or_xor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:53 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:53 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_and(t_car *car)
{
	ft_printf("and %d %d r%hhd\n",
		car->op_args[0],
		car->op_args[1],
		car->op_args[2]);
}

void	print_or(t_car *car)
{
	ft_printf("or %d %d r%hhd\n",
		car->op_args[0],
		car->op_args[1],
		car->op_args[2]);
}

void	print_xor(t_car *car)
{
	ft_printf("xor %d %d r%hhd\n",
		car->op_args[0],
		car->op_args[1],
		car->op_args[2]);
}
