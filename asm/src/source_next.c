/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:43:55 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 12:03:53 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void	skip_whitespace(t_src *s)
// {
// 	while (*(char *)&s->buf.data[s->index])
// 	{
// 		if (*(char *)&s->buf.data[s->index] == '\n')
// 			return ;
// 		if (!ft_isspace(*(char *)&s->buf.data[s->index]))
// 			return ;
// 		s->index++;
// 		s->col++;
// 	}
// }

void	source_next(t_src *s)
{
	skip_whitespace(s);
	if (s->index)
		s->prev = &s->buf.data[s->index - 1];
	if (s->index < s->buf.len)
		s->next = &s->buf.data[s->index + 1];
}