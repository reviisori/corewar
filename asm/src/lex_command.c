/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:29:33 by altikka           #+#    #+#             */
/*   Updated: 2022/11/22 14:27:40 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	create_statement(t_sh *d, char *key)
{
	t_statement	temp;
	t_hash		*entry;

	entry = hash_get(&d->ops, key);
	temp.op = g_optab[entry->value - 1];
	temp.loc = d->byte;
	d->byte += 1 + g_optab[temp.op.op_code - 1].acb;
	temp.cur_arg = 0;
	temp.sep = 0;
	temp.is_dir = false;
	if (ft_vecpush(&d->code, &temp) < 0)
		panic("Malloc error with exec code.");
}

static void	lex_operation(t_sh *d, t_src *s, t_token *t)
{
	char	*p;
	size_t	ofs;

	t->symbol = la_op;
	p = (char *)&s->buf.data[s->index];
	while (is_label_chars(*p))
		p++;
	ofs = p - (char *)&s->buf.data[s->index];
	ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
	ft_vecpush(&t->content, "\0");
	if (!hash_lookup(&d->ops, (char *)t->content.data))
		panic_lex("...", 0, 0); //?
	create_statement(d, (char *)t->content.data);
	source_adjust(s, ofs);
}

static void	command_label(t_sh *d, t_labtab *lt, char *key)
{
	t_hash	*entry;

	entry = hash_get(&lt->labels, key);
	if (!entry)
		hash_insert(&lt->labels, key, d->byte);
	else if (entry)
	{
		label_fill(d, &lt->entries, entry);
		ft_strdel(&key);
	}
}

void	lex_command(t_sh *d, t_src *s, t_token *t, t_labtab *lt)
{
	char	*p;
	size_t	ofs;

	if (is_label(s))
	{
		t->symbol = la_label;
		t->is_label = true;
		p = ft_strchr(&s->buf.data[s->index], LABEL_CHAR);
		ofs = p - (char *)&s->buf.data[s->index] + 1;
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs - 1);
		ft_vecpush(&t->content, "\0");
		command_label(d, lt, ft_strndup((char *)t->content.data, t->content.len));
		source_adjust(s, ofs);
	}
	else
		lex_operation(d, s, t);
}
