/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:15:33 by altikka           #+#    #+#             */
/*   Updated: 2022/10/26 16:28:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

typedef struct s_src
{
	t_vec	buf;
	size_t	row;
	size_t	col;
	size_t	index;
	char	*prev;
	char	*next;
}			t_src;

void	init_source(t_src *s);
//int		panic_source(t_src *s, const char *msg);
//void	free_source(t_src *s);

#endif
