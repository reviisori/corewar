/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:03:04 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/21 16:03:06 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_handler_champ_size(char *message, char *file, int size, int max)
{
	ft_dprintf(2, message, file, size, max);
	exit(1);
}

void	error_handler(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}
