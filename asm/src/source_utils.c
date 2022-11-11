/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:11:26 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/11 15:15:39 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	source_adjust(t_src *s, int len)
{
	s->index += len;
	s->col += len;
	if (s->index)
		s->prev = &s->buf.data[s->index - 1];
	if (s->index < s->buf.len)
		s->next = &s->buf.data[s->index + 1];
}

void	source_next(t_src *s)
{
	skip_whitespace(s);
	if (s->index)
		s->prev = &s->buf.data[s->index - 1];
	if (s->index < s->buf.len)
		s->next = &s->buf.data[s->index + 1];
}
