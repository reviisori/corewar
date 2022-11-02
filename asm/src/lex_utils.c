/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:35 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 12:03:43 by atenhune         ###   ########.fr       */
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
