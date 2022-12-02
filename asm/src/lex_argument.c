/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:17:37 by altikka           #+#    #+#             */
/*   Updated: 2022/12/01 13:20:50 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	lex_ind(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	char	*p;
	int		arg;
	int		ofs;

	if (!validate_arg(stmt, T_IND))
		panic_invalidarg("indirect", s, stmt);
	p = (char *)&s->buf.data[s->index];
	if (!ft_isdigit(*p) && *p != '-')
		panic_lex(NULL, NULL, s->row, s->col);
	arg = ft_atoi(p);
	stmt->arg_type[stmt->cur_arg] = IND_CODE;
	stmt->args[stmt->cur_arg++] = arg;
	ofs = nbr_len(p);
	t->symbol = la_ind;
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	d->byte += IND_SIZE;
	source_adjust(s, ofs);
}

static void	lex_dir(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	char	*p;
	int		arg;
	int		ofs;

	if (!validate_arg(stmt, T_DIR))
		panic_invalidarg("direct", s, stmt);
	source_next(s);
	p = (char *)&s->buf.data[++s->index];
	if (!ft_isdigit(*p) && *p != '-')
		panic_lex(NULL, NULL, s->row, s->col);
	arg = ft_atoi(p);
	stmt->arg_type[stmt->cur_arg] = DIR_CODE;
	stmt->args[stmt->cur_arg++] = arg;
	ofs = nbr_len(p);
	t->symbol = la_dir;
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	d->byte += stmt->op.size;
	source_adjust(s, ofs);
}

static void	lex_reg(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	int			reg;
	int			ofs;

	if (!validate_arg(stmt, T_REG))
		panic_invalidarg("register", s, stmt);
	reg = ft_atoi((char *)&s->buf.data[++s->index]);
	if (reg < 1 || reg > REG_NUMBER)
		panic_lex(NULL, NULL, s->row, s->col);
	stmt->arg_type[stmt->cur_arg] = REG_CODE;
	stmt->args[stmt->cur_arg++] = reg;
	ofs = ft_intlen(reg);
	t->symbol = la_reg;
	ft_vecncat(&t->content, &s->buf.data[s->index - 1], ofs + 1);
	d->byte += T_REG;
	source_adjust(s, ofs);
}

static void	lex_label_arg(t_sh *d, t_src *s, t_labtab *lt, t_statement *stmt)
{
	char		*p;

	p = (char *)&s->buf.data[s->index];
	if (*p == DIRECT_CHAR && stmt->op.size == 2)
		stmt->is_dir = true;
	if (*p == DIRECT_CHAR)
	{
		if (!validate_arg(stmt, T_DIR))
			panic_invalidarg("direct", s, stmt);
	}
	else
	{
		if (!validate_arg(stmt, T_IND))
			panic_invalidarg("indirect", s, stmt);
	}
	lex_label(d, s, lt, NULL);
	calc_arg_size(d, stmt, *p);
	stmt->arg_type[stmt->cur_arg] = IND_CODE - (stmt->is_dir);
	stmt->cur_arg++;
}

void	lex_argument(t_sh *d, t_src *s, t_token *t, t_labtab *lt)
{
	t_statement	*stmt;
	char		*p;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	if (!stmt)
		panic_lex("Syntax", t, s->row, s->col); //?
	validate_separators(stmt, s->row, s->col);
	p = (char *)&s->buf.data[s->index];
	if (stmt->cur_arg == stmt->op.argc)
		panic_lex(NULL, NULL, s->row, s->col);
	if (is_register(s))
		lex_reg(d, s, t, stmt);
	else if (*p == DIRECT_CHAR && *s->next != LABEL_CHAR)
		lex_dir(d, s, t, stmt);
	else if (*p == LABEL_CHAR || ft_isdigit(*p) || *p == '-')
		lex_ind(d, s, t, stmt);
	else
	{
		t->symbol = la_arglabel;
		lex_label_arg(d, s, lt, stmt);
	}
}
