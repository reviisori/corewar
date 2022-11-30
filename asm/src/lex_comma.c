/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_comma.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:45:36 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 12:10:10 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_separators(t_statement *stmt, int row, int col)
{
	if (stmt->sep != stmt->cur_arg || stmt->sep == stmt->op.argc)
		panic_lex(NULL, NULL, row, col);
}

void	lex_comma(t_sh *d, t_src *s, t_token *t)
{
	t_statement *stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	if (!stmt || stmt->op.argc == 1)
		panic_lex(NULL, NULL, s->row, s->col); // remember check all vecgets
	stmt->sep++;
	validate_separators(stmt, s->row, s->col);
	t->symbol = la_comm;
	ft_vecncat(&t->content, ",", 1);
	source_adjust(s, 1);
}