/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:49:05 by altikka           #+#    #+#             */
/*   Updated: 2022/11/08 17:08:20 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

typedef struct s_statement
{
	t_op		op;
	u_int8_t	acb;
	int			args[3];
	u_int32_t	loc;
}

typedef struct s_sh
{
	t_header	header;
	t_vec		footer;
	t_hashmap	operations;
}				t_sh;

#endif
