/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/18 14:55:02 by atenhune         ###   ########.fr       */
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
	char	*symbols[15] = {"la_unknown", "la_eof", "la_eol", "la_label",
		"la_op", "la_comm", "la_champname", "la_champcomm", "la_reg",
		"la_dir", "la_ind", "la_num", "la_comma", "la_minus", "la_plus"};

	if (t->symbol == la_unknown)
		ft_printf("%2d: token "RED"%s"EOC": %c", t->num, symbols[t->symbol], *(char *)&s->buf.data[s->index]);
	else
		ft_printf("%2d: token "YELLOW"%s"EOC": ", t->num, symbols[t->symbol]);
	write(1, t->content.data, t->content.len);
	ft_printf("\n");
}

int	lex(t_sh *d, t_src *s)
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
		t.num = (int ) count++; //what is this
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
	check_labels(s, &lt);
	return (1);
}
