/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:20:03 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 21:53:57 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_file(int argc, char *filename)
{
	char	*ext;

	if (argc != 2)
		return (0);
	ext = ft_strrchr(filename, '.');
	return (ft_strnequ(ext, ".s", 3));
}

int	panic(const char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
