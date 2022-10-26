/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:20:03 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 16:07:57 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_file(int argc, char *filename)
{
	char	*temp;

	if (argc != 2)
		return (0);
	temp = ft_strrchr(filename, '.');
	return (ft_strnequ(temp, ".s", 3));
}
