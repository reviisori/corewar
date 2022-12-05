/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/05 16:46:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	reset_token(t_token *t)
{
	t->symbol = la_unknown;
	t->content.len = 0;
	t->declared = false;
	t->is_label = false;
}

static void	debug_lex(t_token *t, t_src *s)
{
	if (t->symbol == la_unknown)
		ft_printf("%2d: token "RED"%s"EOC": %c", t->num, g_symstrs[t->symbol],
			*(char *)&s->buf.data[s->index]);
	else
		ft_printf("%2d: token "YELLOW"%s"EOC": ", t->num, g_symstrs[t->symbol]);
	write(1, t->content.data, t->content.len);
	ft_printf("\n");
}

void	lex(t_sh *d, t_src *s)
{
	t_token		t;
	t_labtab	lt;
	size_t		count;

	count = 1;
	init_lex(&t, &lt);
	while (t.symbol != la_eof)
	{
		source_next(s);
		lex_tokenization(d, s, &t, &lt);
		t.num = (int ) count++;
		debug_lex(&t, s);
		if (t.symbol == la_eof)
			continue ;
		if (t.symbol == la_unknown)
		{
			s->index++;
			s->col++;
		}
		reset_token(&t);
	}
	check_labels(&lt);
	free_labtab(&lt);
	ft_vecdel(&t.content);
}
