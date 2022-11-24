/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/11/22 15:56:15 by atenhune         ###   ########.fr       */
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
	if (lex(d, &s) < 0)
		panic("Lexical error.");
	free_source(&s);
	ft_printf("Parsing done - not.\n"); //...
	return (1);
}
