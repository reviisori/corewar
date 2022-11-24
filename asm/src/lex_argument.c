/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:17:37 by altikka           #+#    #+#             */
/*   Updated: 2022/11/24 16:33:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	lex_ind(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	char	*p;
	int		arg;
	int		ofs;

	if (!validate_arg(stmt, T_IND))
		panic_lex(NULL, s->row, s->col);
	p = (char *)&s->buf.data[s->index];
	if (!ft_isdigit(*p) && *p != '-')
		panic_lex(NULL, s->row, s->col);
	arg = ft_atoi(p);
	stmt->arg_type[stmt->cur_arg] = IND_CODE;
	stmt->args[stmt->cur_arg++] = arg;
	ofs = ft_intlen(arg);
	t->symbol = la_ind;
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	d->byte += T_IND;
	source_adjust(s, ofs);
}

static void	lex_dir(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	char	*p;
	int		arg;
	int		ofs;

	if (!validate_arg(stmt, T_DIR))
		panic_lex(NULL, s->row, s->col);
	source_next(s);
	p = (char *)&s->buf.data[++s->index];
	if (!ft_isdigit(*p))
		panic_lex(NULL, s->row, s->col);
	arg = ft_atoi(p);
	stmt->arg_type[stmt->cur_arg] = DIR_CODE;
	stmt->args[stmt->cur_arg++] = arg;
	ofs = ft_intlen(arg);
	t->symbol = la_dir;
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	d->byte += T_DIR;
	source_adjust(s, ofs);
}

static void	lex_reg(t_sh *d, t_src *s, t_token *t, t_statement *stmt)
{
	int			reg;
	int			ofs;

	if (!validate_arg(stmt, T_REG))
		panic_lex(NULL, s->row, s->col);
	reg = ft_atoi((char *)&s->buf.data[++s->index]);
	if (reg < 1 || reg > REG_NUMBER)
		panic_lex(NULL, s->row, s->col);
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
		panic_lex("...", 0, 0); //?
	validate_separators(stmt, s->row, s->col);
	p = (char *)&s->buf.data[s->index];
	if (stmt->cur_arg == stmt->op.argc)
		panic_lex(NULL, s->row, s->col); //
	if (is_register(s))
		lex_reg(d, s, t, stmt);
	else if (*p == DIRECT_CHAR && *s->next != LABEL_CHAR)
		lex_dir(d, s, t, stmt);
	else if (*p == LABEL_CHAR)
		lex_ind(d, s, t, stmt);
	else
	{
		t->symbol = la_plus; //change to actual la_...
		lex_label_arg(d, s, lt, stmt);
	}
}
