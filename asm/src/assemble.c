/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:17:29 by altikka           #+#    #+#             */
/*   Updated: 2022/11/29 11:57:48 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	assemble(t_sh *d, char *filename)
{
	int	fd;

	d->filename = create_filename(filename);
	fd = open(d->filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		panic("While creating output file.");
	write_file(d, fd);
	close(fd);
	ft_printf("Writing output program to %s\n", d->filename);
	return (1);
}
