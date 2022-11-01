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

static void	init_options(t_options *opts)
{
	opts->dump = -1;
	opts->next_id = 0;
}

static int	get_index(char *opt)
{
	int	i;

	i = -1;
	while (OPTIONS[++i])
	{
		if (OPTIONS[i] == *opt)
			break ;
	}
	if (i == OPTION_COUNT)
		return (-1);
	return (i);
}

static int	read_option(char **argv, int index, t_options *opts)
{
	int	opt_index;

	if (ft_strlen(&argv[index][1]) != 1)
	{
		if (ft_strncmp("dump", &argv[index][1], 5))
			return (-1);
		if (set_dump(opts, argv[index + 1]) == -1)
			return (-1);
	}
	else
	{
		opt_index = get_index(&argv[index][1]);
		if (opt_index == -1)
			return (-1);
		if (g_jump_table[opt_index](opts, argv[index + 1]) == -1)
			return (-1);
	}
	return (index + 1);
}

int	read_arguments(int argc, char **argv, t_info *info)
{
	t_options	options;
	int			i;

	init_options(&options);
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (options.next_id)
				return (-1);
			i = read_option(argv, i, &options);
			if (i == -1)
				return (-1);
		}
		else
			parse_champion(info, argv[i], &options.next_id);
	}
	if (info->champion_count == 0)
		return (-1);
	return (1);
}
