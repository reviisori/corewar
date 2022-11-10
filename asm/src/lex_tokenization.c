/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:11:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/10 15:07:32 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	lex_tokenization(t_sh *d, t_src *s, t_token *t, t_labtab *lt)
{
	char	*p;

	p = (char *)&s->buf.data[s->index];
	if (ft_isupper(*p))
		panic_lex(NULL, s->row, s->col);
	if (*p == '\n' || *p == '\0')
		lex_endof(s, t);
	else if (*p == '#' || *p == ';')
		lex_comment(s, t);
	else if (*p == '.')
		lex_header(d, s, t);
	else if (is_label_chars(*p) && !is_register(s))
		lex_command(d, s, t, lt); //name hello?
	else if (is_label_chars(*p) || *p == DIRECT_CHAR || *p == '-')
		lex_argument(d, s, t, lt);
}
