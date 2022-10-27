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

void	error_handler(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}
