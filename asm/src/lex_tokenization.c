/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:11:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/04 16:04:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lex_tokenization(t_sh *d, t_src *s, t_token *t)
{
	char	*target;

	target = (char *)&s->buf.data[s->index];
	if (*target == '\n' || *target == '\0')
		lex_endof(s, t);
	else if (*target == '#' || *target == ';')
		lex_comment(s, t);
	else if (*target == '.')
		lex_header(s, t);
	else if (is_label_chars(*target) && !is_register(s))
		lex_command(d, s, t); //name hello?
	//else if (is_label_char (*target) || *target == DIRECT_CHAR);
	//	lex_argument(s, t);
}
