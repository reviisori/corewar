/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:35 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:37 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_add(t_car *car)
{
	ft_printf("add r%hhd r%hhd r%hhd\n",
		car->op_args[0],
		car->op_args[1],
		car->op_args[2]);
}

void	print_sub(t_car *car)
{
	ft_printf("add r%hhd r%hhd r%hhd\n",
		car->op_args[0],
		car->op_args[1],
		car->op_args[2]);
}
