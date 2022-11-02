/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:35 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 17:59:53 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	skip_whitespace(t_src *s)
{
	while (*(char *)&s->buf.data[s->index])
	{
		if (*(char *)&s->buf.data[s->index] == '\n')
			return ;
		if (!ft_isspace(*(char *)&s->buf.data[s->index]))
			return ;
		s->index++;
		s->col++;
	}
}

void	panic_lex(const char *msg, size_t row, size_t col)
{
	if (!msg)
		ft_dprintf(2, "Lexical error at [%zu:%zu]\n", row + 1, col + 1);
	else
		ft_dprintf(2, "call panic_syntax() maybe\n");
	exit(EXIT_FAILURE);
}
