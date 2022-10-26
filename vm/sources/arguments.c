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
	if (i == OPTION_COUNT - 1)
		error_handler(USAGE, NULL);
	return (i);
}

static int	read_option(char **argv, int index, t_options *opts)
{
	if (ft_strlen(&argv[index][1]) != 1)
	{
		if (ft_strncmp("dump", &argv[index][1], 5))
			return (-1);
		if (set_dump(opts, argv[++index]) == -1)
			return (-1);
	}
	else
	{
		index++;
		if (jump_table[get_index(&argv[index][1])](opts, argv[index]) == -1)
			return (-1);
	}
	return (index);
}

void	read_arguments(int argc, char **argv, t_info *info)
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
				error_handler(USAGE, info);
			i = read_option(argv, i, &options);
			if (i == -1)
				error_handler(USAGE, info);
		}
		else
			parse_champion(info, argv[i], &options.next_id);
	}
	if (info->champion_count == 0)
		error_handler(USAGE, info);
}
