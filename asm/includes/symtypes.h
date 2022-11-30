/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:07:22 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 16:55:24 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMTYPES_H
# define SYMTYPES_H

typedef enum e_symtypes
{
	la_unknown,
	la_eof,
	la_eol,
	la_label,
	la_op,
	la_comm,
	la_champname,
	la_champcomm,
	la_reg,
	la_dir,
	la_ind,
	la_arglabel,
	la_comma
}	t_symtypes;

static const char	*g_symstrs[13] = {
	"UNKNOWN",
	"EOF",
	"EOL",
	"LABEL",
	"OPERATION",
	"COMMENT",
	"CHAMPION'S NAME",
	"CHAMPION'S COMMENT",
	"REG",
	"DIR",
	"IND",
	"LABEL AS ARGUMENT",
	"COMMA"
};

typedef struct s_token
{
	t_symtypes		symbol;
	t_vec			content;
	bool			declared;
	bool			is_label;
	int				num;
}					t_token;

#endif
