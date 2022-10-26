/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:44:38 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 17:01:48 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_buf_size(int fd, t_src *s)
{
}

static int	read_to_buf(int fd, t_src *s)
{
}

int	read_source(t_src *s, const char *filename)
{
	int	fd;

	fd = open(filename, 0_RDONLY);
	if (fd < 0)
		return (ft_putendl("Error: open."), exit(0));
	if (read_to_buf(fd, s) < 0)
		return (ft_putendl("Error: GBS."), exit(0));
	return (1);
}
