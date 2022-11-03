/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:45:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/03 14:26:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*find_ending_quote(t_src *s)
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

static void	get_header_info(t_src *s, t_token *t, char c)
{
	char	*p;

	if (*(char *)&s->buf.data[s->index] != '"')
		panic_lex(NULL, s->row, s->col);
	p = find_ending_quote(s);
	if (p)
	{
		if (p - (char *)&s->buf.data[s->index] + 1 > PROG_NAME_LENGTH
			&& c == 'n')
			panic_lex("name", PROG_NAME_LENGTH, 0);
		if (p - (char *)&s->buf.data[s->index] + 1 > COMMENT_LENGTH
			&& c == 'n')
			panic_lex("name", COMMENT_LENGTH, 0);
		ft_vecncat(&t->content, &s->buf.data[s->index],
			p - (char *)&s->buf.data[s->index] + 1);
		s->index += p - (char *)&s->buf.data[s->index] + 1;
	}
	else
		panic_lex("...", 0, 0);
}

void	lex_header(t_src *s, t_token *t)
{
	if (!ft_strncmp(&s->buf.data[s->index], ".name", 5))
	{
		t->symbol = la_champname;
		s->index += 5;
		s->col += 5;
		skip_whitespace(s);
		get_header_info(s, t, 'n');
	}
	else if (!ft_strncmp(&s->buf.data[s->index], ".comment", 8))
	{
		t->symbol = la_champcomm;
		s->index += 8;
		s->col += 8;
		skip_whitespace(s);
		get_header_info(s, t, 'c');
	}
}
