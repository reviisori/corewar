/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:29:02 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 15:38:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	if (!valid_file(argc, argv[1]))
		return (ft_putstr(ASM_USAGE), -1);
	if (!parse(argv[1]))
		ft_putendl("parsing error");
	if (!assemble(argv[1]))
		ft_putendl("avengers didn't assemble :(");
	return (0);
}
