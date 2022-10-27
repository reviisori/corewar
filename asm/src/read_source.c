/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:44:38 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 09:26:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static off_t	get_buf_size(int fd)
{
	off_t	start;
	off_t	size;

	start = lseek(fd, 0, SEEK_CUR);
	size = lseek(fd, 0, SEEK_END);
	if (start == -1 || size == -1 || start == size)
		panic_source(fd, "Couldn't get buffer size.");
	return (size);
}

static int	read_to_buf(int fd, t_src *s)
{
	size_t	buf_size;

	buf_size = (size_t) get_buf_size(fd);
	(void)s; //here ft_vecresize()
	return (1);
}

int	read_source(t_src *s, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		panic("Opening file failed.");
	if (read_to_buf(fd, s) < 0)
		panic("Reading file failed.");
	close(fd);
	return (1);
}
