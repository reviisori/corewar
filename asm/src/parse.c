/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 09:26:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	parse(char *filename)
{
	t_src	s;

	init_source(&s);
	if (read_source(&s, filename) < 0)
		panic("Invalid source file.");
	ft_printf("Parsing done - not.\n"); //...
	return (1);
}
