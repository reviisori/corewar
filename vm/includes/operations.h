/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:32 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/08 12:46:33 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "corewar.h"

/* Operation macros */
# define OP_COUNT 1

void	op_st(t_info *info, t_car *car);

typedef void				(*t_operations)(t_info *, t_car *);

static const t_operations	g_op_jump_table[OP_COUNT] = {
	op_st
};

#endif
