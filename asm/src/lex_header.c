/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:45:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/10 12:48:59 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*find_ending_quotation(t_src *s)
{
	char	*ptr;

	ptr = (char *)&s->buf.data[s->index + 1];
	while (*ptr != '"')
	{
		s->col++;
		if (*ptr == '\0')
			return (NULL);
		if (*ptr == '\n')
		{
			s->row++;
			s->col = 0;
		}
		ptr++;
	}
	return (ptr);
}

static void	get_header_info(t_sh *d, t_src *s, t_token *t, char c)
{
	char	*p;
	size_t	ofs;

	if (*(char *)&s->buf.data[s->index] != '"')
		panic_lex(NULL, s->row, s->col);
	p = find_ending_quotation(s);
	if (p)
	{
		s->index++;
		ofs = p - (char *)&s->buf.data[s->index];
		if (ofs > PROG_NAME_LENGTH
			&& c == 'n')
			panic_lex("name", PROG_NAME_LENGTH, 0);
		if (ofs > COMMENT_LENGTH
			&& c == 'c')
			panic_lex("comment", COMMENT_LENGTH, 0);
		ft_vecncat(&t->content, &s->buf.data[s->index], ofs);
		if (c == 'n')
			ft_memcpy(&d->header.prog_name, &t->content, ofs);
		else
			ft_memcpy(&d->header.comment, &t->content, ofs);
		s->index += ofs + 1;
	}
	else
		panic_lex("...", 0, 0); //?
}

void	lex_header(t_sh *d, t_src *s, t_token *t)
{
	if (!ft_strncmp(&s->buf.data[s->index], ".name", 5))
	{
		t->symbol = la_champname;
		s->index += 5;
		s->col += 5;
		source_next(s);
		get_header_info(d, s, t, 'n');
	}
	else if (!ft_strncmp(&s->buf.data[s->index], ".comment", 8))
	{
		t->symbol = la_champcomm;
		s->index += 8;
		s->col += 8;
		source_next(s);
		get_header_info(d, s, t, 'c');
	}
}
