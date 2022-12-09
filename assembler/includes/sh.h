/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:49:05 by altikka           #+#    #+#             */
/*   Updated: 2022/12/09 10:43:20 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

typedef struct s_statement
{
	t_op		op;
	u_int8_t	acb;
	int			args[3];
	u_int8_t	arg_type[3];
	int			cur_arg;
	int			sep;
	bool		is_dir;
	bool		is_valid;
	u_int32_t	loc;
}				t_statement;

typedef struct s_sh
{
	t_header	header;
	t_vec		code;
	t_hashmap	ops;
	bool		op_in_line;
	char		*filename;
	u_int32_t	byte;
}				t_sh;

#endif
