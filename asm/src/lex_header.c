/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:45:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 14:46:07 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_header_info(t_src *s, t_token *t)
{
	char *p;

	if (*(char *)&s->buf.data[s->index] != '"')
	{
		ft_putendl("Error in .name or .comment (FIXTHIS)");
		exit(0);
	}
	p = ft_strchr(&s->buf.data[s->index + 1], '"');
	if (p)
	{
		ft_vecncat(&t->content, &s->buf.data[s->index],
			p - (char *)&s->buf.data[s->index] + 1);
		s->index += p - (char *)&s->buf.data[s->index] + 1;
	}
	else
	{
		ft_putendl("Error in .name or .comment (FIXTHIS)");
		exit(0);
	}
}

void	lex_header(t_src *s, t_token *t)
{
	if (!ft_strncmp(&s->buf.data[s->index], ".name", 5))
	{
		t->symbol = la_champname;
		s->index += 5;
		skip_whitespace(s);
		get_header_info(s, t);
	}
	else if (!ft_strncmp(&s->buf.data[s->index], ".comment", 8))
	{
		t->symbol = la_champcomm;
		s->index += 8;
		skip_whitespace(s);
		get_header_info(s, t);
	}
}