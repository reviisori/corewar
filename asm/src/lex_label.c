/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:02 by altikka           #+#    #+#             */
/*   Updated: 2022/11/11 21:31:10 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_fill(t_sh *d, t_vec *entries, t_hash *entry)
{
	//t_statement	*temp;
	t_label		*label;

	label = ft_vecget(entries, ft_abs(entry->value + 1));
	ft_printf("....>%d\n", entry->value);
	entry->value = d->byte;
	ft_printf("....>%d\n", entry->value);
	exit(1);
}

static void	label_add(t_sh *d, t_label *lab)
{
	t_statement	*temp;
	t_undeflab	*temp_node;
	t_undeflab	*node;

	temp = ft_vecget(&d->code, d->code.len - 1);
	node = (t_undeflab *)ft_memalloc(sizeof(t_undeflab));
	if (!node)
		panic("Malloc error while adding a label node.");
	node->stmt = d->code.len - 1;
	node->arg = temp->cur_arg;
	node->loc = d->byte;
	//node->is_dir = lab->is_dir;
	node->next = NULL;
	if (!lab->head)
	{
		lab->head = node;
		return ;
	}
	temp_node = lab->head->next;
	while (temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = node;
}

static char	*get_label(t_src *s, bool *is_arg)
{
	char	*key;
	char	*p;

	*is_arg = true;
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

void	lex_label(t_sh *d, t_src *s, t_labtab *lt, char *key)
{
	t_hash	*entry;
	t_label	label;
	bool	is_arg;


	is_arg = false;
	if (!key)
		key = get_label(s, &is_arg);
	entry = hash_get(&lt->labels, key);
	if (!entry && is_arg == false)
		hash_insert(&lt->labels, key, d->byte);
	else if (!entry && is_arg == true)
	{
		label.declared = false;
		//label.is_dir = REMEMBER ME
		label.head = NULL;
		label_add(d, &label);
		ft_vecpush(&lt->entries, &label);
		hash_insert(&lt->labels, key, ((int)lt->entries.len * -1));
	}
	else if (entry && is_arg == true)
		ft_printf("you need me!\n");
	else if (entry && is_arg == false)
		label_fill(d, &lt->entries, entry);
	//if (is_arg == true)
	//	ft_strdel(&key);
}
