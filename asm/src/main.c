/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:29:02 by altikka           #+#    #+#             */
/*   Updated: 2022/10/28 13:52:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_sh	d;

	if (!valid_file(argc, argv[1]))
		panic(ASM_USAGE);
	if (!parse(&d, argv[1]))
		panic("Parsing failed.");
	if (!assemble(argv[1])) //send asm
		panic("Avengers didn't assemble.");
	return (0);
}
