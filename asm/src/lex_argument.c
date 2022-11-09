/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:17:37 by altikka           #+#    #+#             */
/*   Updated: 2022/11/09 17:35:30 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	lex_reg(t_sh *d, t_src *s, t_token *t)
{
	t_statement	*temp;
	int			reg;
	int			ofs;

	reg = ft_atoi((char *)&s->buf.data[++s->index]);
	if (reg > REG_NUMBER || reg <= 0)
		panic_lex(NULL, s->row, s->col);
	temp = ft_vecget(&d->code, d->code.len - 1);
	temp->args[temp->cur_arg++] = reg;
	ofs = ft_intlen(reg);
	t->symbol = la_reg;
	ft_vecncat(&t->content, &s->buf.data[s->index - 1], ofs + 1);
	d->byte += 1;
	s->index += ofs;
	s->col += ofs;
}

void	lex_argument(t_sh *d, t_src *s, t_token *t)
{
	char	*p;

	p = (char *)&s->buf.data[s->index];
	if (is_register(s))
		lex_reg(d, s, t);
	//else if (*p == DIRECT_CHAR)
	//	lex_dir();
	//else
	//	lex_ind();
}
