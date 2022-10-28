/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/28 18:46:12 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	eo(t_src *s, t_token *t)
{
	if (*(char *)&s->buf.data[s->index] == '\n')
	{
		ft_printf("token: EOL\n");
		s->index++;
	}
	if (*(char *)&s->buf.data[s->index] == '\0')
	{
		ft_printf("token: EOF\n");
		t->symbol = la_eof;
	}
}

int	lex(t_sh *d, t_src *s)
{
	t_token	t;

	(void)d;
	init_token(&t);
	while (t.symbol != la_eof)
	{
		source_next(s);
		eo(s, &t);
	}
	return (1);
}