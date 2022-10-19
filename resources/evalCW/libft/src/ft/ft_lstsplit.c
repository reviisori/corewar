/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:12:32 by rkyttala          #+#    #+#             */
/*   Updated: 2021/08/02 13:07:09 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsplit(char **arr)
{
	int			i;
	t_list		*head;
	t_list		*new;

	i = 0;
	new = ft_lstnew(arr[i], sizeof(char) * ft_strlen(arr[i]));
	if (!new)
		return (0);
	head = new;
	i++;
	while (arr[i] != NULL)
	{
		new->next = ft_lstnew(arr[i], sizeof(char) * ft_strlen(arr[i]));
		if (!new->next)
		{
			free(new);
			return (0);
		}
		new = new->next;
		i++;
	}
	new->next = NULL;
	return (head);
}
