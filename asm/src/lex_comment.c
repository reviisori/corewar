/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/11 15:20:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_comment(t_src *s, t_token *t)
{
	char	*p;

	p = ft_strchr(&s->buf.data[s->index], '\n');
	if (!p)
	{
		ft_vecncat(&t->content, &s->buf.data[s->index],
			s->buf.len - s->index - 1);
		source_adjust(s, s->buf.len - s->index);
	}
	else
	{
		ft_vecncat(&t->content, &s->buf.data[s->index],
			p - (char *)&s->buf.data[s->index]);
		source_adjust(s, p - (char *)&s->buf.data[s->index]);
	}
	t->symbol = la_comm;
}
