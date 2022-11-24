/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:15:33 by altikka           #+#    #+#             */
/*   Updated: 2022/11/11 15:14:10 by atenhune         ###   ########.fr       */
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
void	source_next(t_src *s);
void	source_adjust(t_src *s, int len);
void	skip_whitespace(t_src *s);
void	free_source(t_src *s);

#endif
