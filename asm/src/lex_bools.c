/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_bools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:34:31 by altikka           #+#    #+#             */
/*   Updated: 2022/11/30 17:31:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool	is_label_chars(int c)
{
	return ((c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9'));
}

bool	is_label(t_src *s)
{
	bool	i_was_in_a_while_loop;
	char	*p;

	i_was_in_a_while_loop = false;
	p = (char *)&s->buf.data[s->index];
	while (is_label_chars(*p))
	{
		i_was_in_a_while_loop = true;
		p++;
	}
	return (*p == LABEL_CHAR && i_was_in_a_while_loop);
}

bool	is_register(t_src *s)
{
	char	*p;

	p = (char *)&s->buf.data[s->index];
	if (*p++ != 'r')
		return (false);
	while (ft_isdigit(*p))
		p++;
	return ((ft_isspace(*p) || *p == SEPARATOR_CHAR || *p == COMMENT_CHAR
			|| *p == ';'));
}
