/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_byte_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:25 by asuikkan          #+#    #+#             */
/*   Updated: 2022/11/08 13:01:26 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define RIGHTMOST_TWO_BITS 0x03

unsigned char	get_crumb(unsigned char c_byte, int c_number)
{
	unsigned char	crumb;

	crumb = (c_byte >> (CRUMBS_IN_BYTE - c_number) * 2) & RIGHTMOST_TWO_BITS;
	return (crumb);
}
