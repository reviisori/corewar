/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:11:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/02 13:39:50 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_tokenization(t_src *s, t_token *t)
{
	char *target;

	target = (char *)&s->buf.data[s->index];
	if (*target == '\n' || *target == '\0')
		lex_endof(s, t);
	else if (*target == '#' || *target == ';')
		lex_comment(s, t);
	else if (*target == '.')
		lex_header(s, t);
}