/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:15:33 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 09:17:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <fcntl.h>

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
int		read_source(t_src *s, const char *filename);
void	panic_source(int fd, const char *msg);
void	free_source(t_src *s);

#endif
