/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:12:50 by altikka           #+#    #+#             */
/*   Updated: 2022/11/04 13:06:19 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_token(t_token *t)
{
	ft_bzero(t, sizeof(*t));
	t->symbol = la_unknown;
	if (ft_vecnew(&t->content, 1, sizeof(char)) < 0)
		panic("Couldn't initialize token content.");
	t->declared = false;
	t->is_label = false;
	t->num = 1;
	t->next = NULL;
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

static void init_operations(t_hashmap *ops)
{
	if (hash_new(ops, 32) < 0)
		panic("Couldn't initialize hashmap.");
	
}

void	init_handler(t_sh *d)
{
	ft_bzero(d, sizeof(*d));
	ft_bzero(&d->header, sizeof(&d->header));
	d->header.magic = COREWAR_EXEC_MAGIC;
	d->header.prog_size = 0;
}
