/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:55:19 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/22 16:18:55 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	write_file(t_sh *d, char *filename)
{
	int	fd;

	d->filename = create_filename(filename);

	fd = open(d->filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		panic("While creating output file.");
	ft_dprintf(fd, "%x", 123);
	ft_dprintf(fd, "%x", 123);
	ft_dprintf(fd, "%x", 123);
	close(fd);
	return (1);
}