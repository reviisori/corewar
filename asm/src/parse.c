/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 16:47:55 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	parse(char *filename)
{
	t_src	s;

	init_source(&s);
	if (read_source(&s, filename) < 0)
		exit(0); //msg
	ft_printf("parsing done - not.\n");
	return (1);
}
