/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:46:17 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/20 17:46:19 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_player_number(char *id, int *dst)
{
	if (id == NULL)
		error_handler(USAGE, NULL);
	*dst = ft_atoi(id);
	if (*dst <= 0)
		error_handler(USAGE, NULL);
}

static int	set_dump(char *nbr, int *dst)
{
	if (nbr == NULL)
		return (-1);
	*dst = ft_atoi(nbr);
	return (1);
}

static void	read_option(char **argv, int index, t_info *info)
{
	int	j;

	j = 0;
	if (ft_strlen(&argv[index][1]) != 1)
	{
		if (ft_strncmp("dump", &argv[index][1], 5))
			error_handler(USAGE, info);
		if (set_dump(argv[index + 1], &info->dump_cycles) == -1)
			error_handler(USAGE, info);
	}
	else
	{
		if (argv[index][1] == 'n')
			set_player_number(argv[index + 1], &info->current_id);
	}
}

void	read_arguments(int argc, char **argv, t_info *info)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			read_option(argv, i, info);
	}
}
