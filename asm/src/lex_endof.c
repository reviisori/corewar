/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_endof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:21:04 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/31 12:12:11 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_endof(t_src *s, t_token *t)
{
	if (*(char *)&s->buf.data[s->index] == '\n')
	{
		t->symbol = la_eol;
		*(char *)&t->content.data[0] = '\n';
		s->row++;
		s->col = 0;
		s->index++;
	}
	if (*(char *)&s->buf.data[s->index] == '\0')
	{
		t->symbol = la_eof;
		*(char *)&t->content.data[0] = '\0';
	}
}
