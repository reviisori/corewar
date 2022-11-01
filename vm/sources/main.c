/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:43:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/20 16:43:39 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_info(t_info *info)
{
	info->dump_cycles = -1;
	info->champion_count = 0;
	ft_bzero(info->champions, sizeof(t_champion) * MAX_PLAYERS);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		print_usage(USAGE);
	init_info(&info);
	if (read_arguments(argc, argv, &info) == -1)
		print_usage(USAGE);
	check_champions(info.champions, info.champion_count);
	return (0);
}
