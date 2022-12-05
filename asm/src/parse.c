/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:15 by altikka           #+#    #+#             */
/*   Updated: 2022/12/01 11:47:16 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse(t_sh *d, char *filename)
{
	t_src	s;

	init_handler(d);
	init_source(&s);
	read_source(&s, filename);
	lex(d, &s);
	free_source(&s);
}
