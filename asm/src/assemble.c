/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:17:29 by altikka           #+#    #+#             */
/*   Updated: 2022/11/22 16:08:46 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	assemble(t_sh *d, char *filename)
{
	write_file(d, filename);
	ft_printf("asm done - I wish.\n");
	return (1);
}
