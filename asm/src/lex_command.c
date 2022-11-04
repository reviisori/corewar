/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:29:33 by altikka           #+#    #+#             */
/*   Updated: 2022/11/04 12:26:27 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_command(t_src *s, t_token *t)
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
		t->symbol = la_op
		p = (char *)&s->buf.data[s->index];
		ft_printf("OP\n"); //here
	}
}
