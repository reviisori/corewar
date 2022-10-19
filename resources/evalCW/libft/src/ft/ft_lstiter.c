/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:52:27 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:06:54 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*move;

	tmp = lst;
	while (tmp != NULL)
	{
		move = tmp->next;
		f(tmp);
		tmp = move;
	}
}
