/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_byte_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:25 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/08 13:01:26 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

#define RIGHTMOST_TWO_BITS 0x03

unsigned char	get_crumb(unsigned char c_byte, int c_number)
{
	unsigned char	crumb;

	crumb = (c_byte >> (CRUMBS_IN_BYTE - c_number) * 2) & RIGHTMOST_TWO_BITS;
	return (crumb);
}

/* Finds argument n (where 1 <= n <= 3, 4 is for theoretical statements)
	for the carriages current op */
unsigned int	get_argument(t_info *info, unsigned char n, t_car *car)
{
	unsigned char	arg_type;

	if (n < 1 || n > 4 || (n > 1 && !g_op[car->op][C_BYTE]))
		error_kill("invalid argument count ");//shouldn't ever ever ever happen
	if (!g_op[car->op][C_BYTE])
	{
		if(car->op == 0x01)
			return ((info->memory[(car->pc + 1) % MEM_SIZE] << 6) 
				+ (info->memory[(car->pc + 2) % MEM_SIZE] << 4)
				+ (info->memory[(car->pc + 3) % MEM_SIZE] << 2)
				+ (info->memory[(car->pc + 4) % MEM_SIZE]));
		return ((info->memory[(car->pc + 1) % MEM_SIZE] << 2) 
			+ (info->memory[(car->pc + 2) % MEM_SIZE]);
	}
	return (0);
	//arg_type = get_crumb(info->memory[car->pc + ])
}