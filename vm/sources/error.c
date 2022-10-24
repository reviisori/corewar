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

static void	cleanup(t_info *info)
{
	(void)info;
}

void	error_handler(char *message, t_info *info)
{
	cleanup(info);
	ft_putendl_fd(message, 2);
	exit(1);
}
