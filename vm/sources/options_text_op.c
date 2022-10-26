/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_text_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:40:48 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/25 14:40:51 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	set_dump(t_options *opts, char *nbr)
{
	if (nbr == NULL)
		return (-1);
	opts->dump = ft_atoi(nbr);
	return (1);
}
