/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:11:26 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/14 16:32:36 by altikka          ###   ########.fr       */
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

void	skip_whitespace(t_src *s)
{
	while (*(char *)&s->buf.data[s->index])
	{
		if (*(char *)&s->buf.data[s->index] == '\n')
			return ;
		if (!ft_isspace(*(char *)&s->buf.data[s->index]))
			return ;
		source_adjust(s, 1);
	}
}

void	source_next(t_src *s)
{
	skip_whitespace(s);
	if (s->index)
		s->prev = &s->buf.data[s->index - 1];
	if (s->index < s->buf.len)
		s->next = &s->buf.data[s->index + 1];
}
