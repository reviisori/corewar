/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:31:37 by altikka           #+#    #+#             */
/*   Updated: 2022/12/08 09:43:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	debug_statement(t_sh *d)
{
	t_statement	*stmt;
	size_t		i;

	i = 0;
	return ;
	while (i < d->code.len)
	{
		stmt = ft_vecget(&d->code, i);
		ft_printf(""CYAN"OP"EOC": %s [%d", stmt->op.name, stmt->args[0]);
		if (stmt->op.argc == 1)
			ft_printf("]\n");
		if (stmt->op.argc == 2)
			ft_printf(", %d]\n", stmt->args[1]);
		if (stmt->op.argc == 3)
			ft_printf(", %d, %d]\n", stmt->args[1], stmt->args[2]);
		i++;
	}
}

void	debug_lex(t_token *t, t_src *s, size_t tnum)
{
	if (t->symbol == la_unknown)
		ft_printf("%2d: token "RED"%s"EOC": %c", tnum, g_symstrs[t->symbol],
			*(char *)&s->buf.data[s->index]);
	else
		ft_printf("%2d: token "YELLOW"%s"EOC": ", tnum, g_symstrs[t->symbol]);
	write(1, t->content.data, t->content.len);
	ft_printf("\n");
}
