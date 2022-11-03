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

static void	print_champions(t_champion ch_list[])	//temp
{
	int			i;
	t_champion	current;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		current = ch_list[i];
		ft_printf("NUMBER:\t\t%d\n", current.id);
		ft_printf("NAME:\t\t%s\n", current.name);
		ft_printf("COMMENT:\t%s\n", current.comment);
		ft_printf("CODE SIZE:\t%u\n", current.code_size);
		ft_putendl("");
	}
}

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
	print_champions(info.champions);	//temp
	run_game(&info);
	return (0);
}
