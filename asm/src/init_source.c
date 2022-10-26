/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:09:27 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 21:56:38 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	init_source(t_src *s)
{
	if (ft_vecnew(&s->buf, 1, sizeof(char)) < 0)
		return (panic("Couldn't initialize source buffer."));
	s->row = 0;
	s->col = 0;
	s->index = 0;
	s->prev = NULL;
	s->next = NULL;
	return (1);
}
