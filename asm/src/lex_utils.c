/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:35 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/24 14:37:07 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	validate_arg(t_statement *s, int arg)
{
	return (s->op.args[s->cur_arg] == (s->op.args[s->cur_arg] | arg));
}

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
