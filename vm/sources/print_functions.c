/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:18 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 13:06:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_operation(t_car *car)
{
	ft_printf("P%5d | ", car->index);
	g_op_print[car->op](car);
	ft_bzero(car->op_args, MAX_ARGS_NUMBER * sizeof(unsigned int));
	ft_bzero(car->op_arg_types, MAX_ARGS_NUMBER * sizeof(unsigned char));
}
