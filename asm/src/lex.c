/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:15:25 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/31 14:29:41 by atenhune         ###   ########.fr       */
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

int	lex(t_sh *d, t_src *s)
{
	t_token	t;
	size_t	count;

	(void)d;

	count = 1;
	init_token(&t);
	// ft_printf("moro\n");
	// exit(0);
	while (t.symbol != la_eof)
	{
		source_next(s);
		lex_tokenization(s, &t);
		t.num = (int ) count++; //
		ft_printf("%2d: token %d: ", t.num, t.symbol);
		write(1, t.content.data, t.content.len);
		ft_printf("\n");
		if (t.symbol == la_eof)
			exit(1);
		reset_token(&t);
	}
	return (1);
}