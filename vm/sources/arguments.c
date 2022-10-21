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

static void	read_option(char **argv, int index)
{
	int	j;

	j = 0;
	if (!argv[index][++j])
		error_handler(INVALID_OPTION);
}

int	read_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			read_option(argv, i);
	}
	return (1);
}
