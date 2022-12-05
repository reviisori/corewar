/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:40:27 by atenhune          #+#    #+#             */
/*   Updated: 2022/12/01 13:41:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_labels(t_src *s, t_labtab *lt)
{
	t_label *temp;
	size_t	i;
	(void)s; ///what
	i = 0;
	while (i < lt->entries.len)
	{
		temp = ft_vecget(&lt->entries, i);
		if (!temp)
		{
			ft_printf("YEP\n");
			continue ;
		}
		if (temp->declared == false)
		{
			ft_printf("No such label %s while attempting to dereference token"
				"[%zu:%zu] LABEL AS ARGUMENT \"%s\"\n", temp->name,
				temp->pos[0] + 1, temp->pos[1] + 1, temp->name);
			panic("Label missing"); //
		}
		i++;
	}
}
