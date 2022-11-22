/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:56:16 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/22 16:03:48 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*create_filename(char *src)
{
	char *filename;
	char *ret;

	filename = ft_strndup(src, ft_strlen(src) - 1);
	ret = ft_strjoin(filename, "cor");
	ft_strdel(&filename);
	return (ret);
}