/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/10/28 14:04:10 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	parse(t_sh *d, char *filename)
{
	t_src	s;

	init_handler(d);
	init_source(&s);
	if (read_source(&s, filename) < 0)
		panic("Invalid source file.");
	//if (parse_header(d, &s) < 0)
	//	panic("Invalid champion information.");
	ft_printf("Parsing done - not.\n"); //...
	return (1);
}
