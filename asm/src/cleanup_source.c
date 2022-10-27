/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:16:26 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 09:14:26 by altikka          ###   ########.fr       */
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
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	close(fd);
	exit(EXIT_FAILURE);
}
