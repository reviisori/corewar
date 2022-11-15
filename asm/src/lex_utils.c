/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:35 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/15 16:50:51 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	calc_arg_size(t_sh *d, t_statement *stmt, const char c)
{
	if (c == DIRECT_CHAR)
	{
		stmt->is_dir = true;
		d->byte += stmt->op.size;
	}
	else
		d->byte += T_IND;
}

bool	is_label_chars(int c)
{
	return ((c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9'));
}

bool	is_label(t_src *s)
{
	char	*p;

	p = (char *)&s->buf.data[s->index];
	while (is_label_chars(*p))
		p++;
	return (*p == LABEL_CHAR);
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

void	panic_lex(const char *msg, size_t row, size_t col)
{
	if (!msg)
		ft_dprintf(2, "Lexical error at [%zu:%zu]\n", row + 1, col + 1);
	else if (ft_strequ(msg, "name") || ft_strequ(msg, "comment"))
		ft_dprintf(2, "Champion %s too long (Max length %zu)\n", msg, row);
	else
		ft_dprintf(2, "call panic_syntax() maybe\n");
	exit(EXIT_FAILURE);
}

//Invalid parameter count for instruction add
