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

static void	print_usage(void)
{
	ft_putendl("Usage: ./corewar [-dump N] <[-n N] champion1.cor> <...>\n"
	"############### TEXT OUTPUT MODE ################\n"
	"\t-dump N\t: Dumps memory to standard output after N cycles and "
	"quits the game\n"
	"############### CHAMPION OPTIONS ###############\n"
	"\t-n N\t: Sets the champions player number to N");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (print_usage(), 1);
	if (read_arguments(argc, argv) == -1)
		return (1);
	return (0);
}
