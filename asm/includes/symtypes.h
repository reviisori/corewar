/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:07:22 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/30 13:26:54 by atenhune         ###   ########.fr       */
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

typedef struct s_token
{
	t_symtypes		symbol;
	t_vec			content;
	bool			declared;
	bool			is_label;
	int				num;
	struct t_token	*next; //not needed?
}					t_token;

#endif
