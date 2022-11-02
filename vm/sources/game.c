/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:43:26 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/01 15:43:28 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_memory(unsigned char memory[])
{
	int				i;
	int				line_len;
	unsigned int	line_count;

	line_len = 64;
	line_count = 0;
	i = -1;
	while (++i < MEM_SIZE)
	{

		if (i % line_len == 0)
			ft_printf("0x%04x :", line_len * line_count++);
		ft_printf(" %02x", memory[i]);
		if ((i + 1) % line_len == 0)
			ft_putendl("");
	}
	exit(0);
}

void	execute_cycles(t_info *info)
{
	int	cycle;

	cycle = 0;
	while (1)
	{
		if (cycle == info->dump_cycles)
			print_memory(info->memory);
		if (cycle == 10000)
			break ;
		cycle++;
	}
}
