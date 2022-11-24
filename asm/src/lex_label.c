/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:02 by altikka           #+#    #+#             */
/*   Updated: 2022/11/24 14:14:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	label_set_arg(t_sh *d, t_hash *entry)
{
	t_statement	*temp_stmt;

	temp_stmt = ft_vecget(&d->code, d->code.len -1);
	if (temp_stmt->is_dir)
		temp_stmt->args[temp_stmt->cur_arg] = entry->value;
	else
		temp_stmt->args[temp_stmt->cur_arg] = d->byte - entry->value;
}

void	label_fill(t_sh *d, t_vec *entries, t_hash *entry)
{
	t_statement	*temp_stmt;
	t_undeflab	*temp_undeflab;
	t_label		*label;

	if (entry->value > -1)
	{
		label_set_arg(d, entry);
		return ;
	}
	label = ft_vecget(entries, ft_abs(entry->value + 1));
	label->declared = true;
	temp_undeflab = label->head;
	while (temp_undeflab)
	{
		temp_stmt = ft_vecget(&d->code, temp_undeflab->stmt);
		if (temp_undeflab->is_dir)
			temp_stmt->args[temp_undeflab->arg] = d->byte;
		else
			temp_stmt->args[temp_undeflab->arg] = temp_undeflab->loc - d->byte;
		temp_undeflab = temp_undeflab->next;
	}
	entry->value = d->byte;
	//remove from entries maybe
}

static void	label_add(t_sh *d, t_label *lab)
{
	t_statement	*temp_stmt;
	t_undeflab	*temp_node;
	t_undeflab	*node;

	temp_stmt = ft_vecget(&d->code, d->code.len - 1);
	node = (t_undeflab *)ft_memalloc(sizeof(t_undeflab));
	if (!node)
		panic("Malloc error while adding a label node.");
	node->stmt = d->code.len - 1;
	node->arg = temp_stmt->cur_arg;
	node->loc = d->byte;
	node->is_dir = lab->is_dir;
	node->next = NULL;
	temp_node = lab->head;
	while (temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = node;
}

static void	label_new(t_sh *d, t_label *lab)
{
	t_statement	*temp_stmt;
	t_undeflab	*node;

	temp_stmt = ft_vecget(&d->code, d->code.len - 1);
	node = (t_undeflab *)ft_memalloc(sizeof(t_undeflab));
	if (!node)
		panic("Malloc error while adding a label node.");
	node->stmt = d->code.len - 1;
	node->arg = temp_stmt->cur_arg;
	node->loc = d->byte;
	node->is_dir = lab->is_dir;
	node->next = NULL;
	lab->head = node;
}

static char	*get_label(t_src *s)
{
	char	*key;
	char	*p;

	p = (char *)&s->buf.data[s->index];
	if (*p == DIRECT_CHAR && *s->next == LABEL_CHAR)
	{
		p += 2;
		source_adjust(s, 2);
	}
	else
	{
		p++;
		source_adjust(s, 1);
	}
	while (is_label_chars(*p))
		p++;
	key = ft_strsub((char *)&s->buf.data[s->index], 0,
			p - (char *)&s->buf.data[s->index]);
	source_adjust(s, ft_strlen(key));
	return (key);
}

static void	label_init(t_sh *d, t_label *l, bool declared, bool is_first)
{
	t_statement	*stmt;

	stmt = ft_vecget(&d->code, d->code.len - 1);
	l->declared = declared;
	l->is_dir = stmt->is_dir;
	if (is_first)
		l->head = NULL;
}

void	lex_label(t_sh *d, t_src *s, t_labtab *lt, char *key)
{
	t_hash	*entry;
	t_label	label;

	key = get_label(s);
	entry = hash_get(&lt->labels, key);
	if (!entry)
	{
		label_init(d, &label, false, true);
		label_new(d, &label);
		ft_vecpush(&lt->entries, &label);
		hash_insert(&lt->labels, key, ((int)lt->entries.len * -1));
	}
	else if (entry)
	{
		if (entry->value < 0)
		{
			label_init(d, ft_vecget(&lt->entries, ft_abs(entry->value + 1)),
				false, false);
			label_add(d, ft_vecget(&lt->entries, ft_abs(entry->value + 1)));
		}
		else
			label_fill(d, &lt->entries, entry);
		ft_strdel(&key);
	}
}
