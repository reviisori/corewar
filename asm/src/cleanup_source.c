/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:16:26 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 20:12:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_source(t_src *s)
{
	ft_vecdel(&s->buf);
	s->prev = NULL;
	s->next = NULL;
}

void	panic_source(int fd, const char *msg)
{
	ft_dprintf(2, "Error: %s\n", msg);
	close(fd);
	exit(EXIT_FAILURE);
}
