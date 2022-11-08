/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:07:22 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/08 12:20:09 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMTYPES_H
# define SYMTYPES_H

typedef enum e_symtypes
{
	la_unknown,		//done
	la_eof,			//done
	la_eol,			//done 
	la_label,		//needs 'add to hashmap'
	la_op,			//done
	la_comm,		//done
	la_champname,	//done
	la_champcomm,	//done
	la_reg,			//
	la_dir,			//
	la_ind,			//
	la_num,			//
	la_comma,		//
	la_minus,		//
	la_plus			//good to have
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
