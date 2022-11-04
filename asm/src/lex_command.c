/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:29:33 by altikka           #+#    #+#             */
/*   Updated: 2022/11/04 16:29:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define GET write(1, "getfukt\n", 8) //vad

void	lex_command(t_sh *d, t_src *s, t_token *t)
{
	char	*p;
	size_t	ofs;

	if (is_label(s))
	{
		t->symbol = la_label;
		t->is_label = true;
		//add to hashmap
		p = ft_strchr(&s->buf.data[s->index], LABEL_CHAR);
		ofs = p - (char *)&s->buf.data[s->index] + 1;
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
		s->index += ofs;
		s->col += ofs;
	}
	else
	{
		t->symbol = la_op;
		p = (char *)&s->buf.data[s->index];
		while (is_label_chars(*p))
			p++;
		ofs = p - (char *)&s->buf.data[s->index];
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
		ft_vecpush(&t->content, "\0");
		if (!hash_lookup(&d->operations, (char *)t->content.data))
			GET;
		s->index += ofs;
		s->col += ofs;
	}
}
