/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:40:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/29 16:42:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_labels(t_src *s, t_labtab *lt)
{
	t_label *temp;
	size_t	i;
	(void)s;
	i = 0;
	while (i < lt->entries.len)
	{
		temp = ft_vecget(&lt->entries, i);
		if (temp->declared == false)
			panic("Label missing"); // this needs to print label's "name" and location.
		i++;
	}
}
// No such label kissa while attempting to dereference token [TOKEN][004:009] DIRECT_LABEL "%:kissa"
// if op start before we get .name AND .comment
