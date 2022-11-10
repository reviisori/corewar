/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:12:50 by altikka           #+#    #+#             */
/*   Updated: 2022/11/10 14:54:12 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_hashmap(t_hashmap *hm, size_t size)
{
	size_t	i;

	if (hash_new(hm, size) < 0)
		panic("Couldn't initialize hashmap.");
	i = 0;
	while (i < OPTAB_SIZE)
	{
		hash_insert(hm, g_optab[i].name, g_optab[i].op_code);
		i++;
	}
}

void	init_lex(t_token *t, t_labtab *lt)
{
	ft_bzero(t, sizeof(*t));
	t->symbol = la_unknown;
	if (ft_vecnew(&t->content, 1, sizeof(char)) < 0)
		panic("Couldn't initialize token content.");
	t->declared = false;
	t->is_label = false;
	t->num = 1;
	t->next = NULL;
	ft_bzero(lt, sizeof(*lt));
	init_hashmap(&lt->labels, 100);
	if (ft_vecnew(&lt->entries, 1, sizeof(t_labtab)) < 0)
		panic("Couldn't initialize label table entries.");
}

void	init_source(t_src *s)
{
	ft_bzero(s, sizeof(*s));
	if (ft_vecnew(&s->buf, 1, sizeof(char)) < 0)
		panic("Couldn't initialize source buffer.");
	s->row = 0;
	s->col = 0;
	s->index = 0;
	s->prev = NULL;
	s->next = NULL;
}

void	init_handler(t_sh *d)
{
	ft_bzero(d, sizeof(*d));
	ft_bzero(&d->header, sizeof(&d->header));
	d->header.magic = COREWAR_EXEC_MAGIC;
	d->header.prog_size = 0;
	if (ft_vecnew(&d->code, 1, sizeof(t_statement)) < 0)
		panic("Couldn't initialize exec code.");
	init_hashmap(&d->ops, 32);
	d->byte = 0;
}
