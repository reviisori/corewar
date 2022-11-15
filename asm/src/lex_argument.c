/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:17:37 by altikka           #+#    #+#             */
/*   Updated: 2022/11/15 16:20:05 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int	validate_arg(t_statement *s, int arg)
{
	return (s->op.args[s->cur_arg] == (s->op.args[s->cur_arg] | arg));
}

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
	stmt->args[stmt->cur_arg++] = reg;
	ofs = ft_intlen(reg);
	t->symbol = la_reg;
	ft_vecncat(&t->content, &s->buf.data[s->index - 1], ofs + 1);
	d->byte += T_REG;
	source_adjust(s, ofs);
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
	else if (*p != DIRECT_CHAR && *p == LABEL_CHAR)
		lex_ind(d, s, t, stmt);
	else
	{
		stmt->is_dir = true;
		lex_label(d, s, lt, NULL);
		calc_arg_size(d, stmt, *p);
		t->symbol = la_plus;
		stmt->cur_arg++;
	}
}
