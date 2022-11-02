/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:43:55 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 18:04:26 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	source_next(t_src *s)
{
	skip_whitespace(s);
	if (s->index)
		s->prev = &s->buf.data[s->index - 1];
	if (s->index < s->buf.len)
		s->next = &s->buf.data[s->index + 1];
}
