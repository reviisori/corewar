/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:29:02 by altikka           #+#    #+#             */
/*   Updated: 2022/12/05 17:03:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	debug_statement(t_sh *d)
{
	t_statement	*stmt;
	size_t		i;

	i = 0;
	return ;
	while (i < d->code.len)
	{
		stmt = ft_vecget(&d->code, i);
		ft_printf(""GREEN"OP"EOC": %s [%d", stmt->op.name, stmt->args[0]);
		if (stmt->op.argc == 1)
			ft_printf("]\n");
		if (stmt->op.argc == 2)
			ft_printf(", %d]\n", stmt->args[1]);
		if (stmt->op.argc == 3)
			ft_printf(", %d, %d]\n", stmt->args[1], stmt->args[2]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_sh	d;

	if (!valid_file(argc, argv[1]))
		panic(ASM_USAGE);
	parse(&d, argv[1]);
	debug_statement(&d);
	assemble(&d, argv[1]);
	return (0);
}
