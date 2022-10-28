/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:12:50 by altikka           #+#    #+#             */
/*   Updated: 2022/10/28 15:25:42 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	exit(1);
}
