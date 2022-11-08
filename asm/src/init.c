/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:12:50 by altikka           #+#    #+#             */
/*   Updated: 2022/11/04 17:12:27 by altikka          ###   ########.fr       */
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

static void	optab_init(t_hashmap *ops)
{
	size_t	i;

	if (hash_new(ops, 32) < 0)
		panic("Couldn't initialize hashmap.");
	i = 0;
	while (i < OPTAB_SIZE)
	{
		hash_insert(ops, g_optab[i].name, g_optab[i].op_code);
		i++;
	}
}

void	init_handler(t_sh *d)
{
	ft_bzero(d, sizeof(*d));
	ft_bzero(&d->header, sizeof(&d->header));
	d->header.magic = COREWAR_EXEC_MAGIC;
	d->header.prog_size = 0;
	optab_init(&d->operations);
}
