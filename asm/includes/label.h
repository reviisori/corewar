/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:12:18 by altikka           #+#    #+#             */
/*   Updated: 2022/11/14 15:49:34 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

typedef struct s_undeflab
{
	u_int32_t			stmt;
	u_int8_t			arg;
	u_int32_t			loc;
	bool				is_dir;
	struct s_undeflab	*next;
}						t_undeflab;

typedef struct s_label
{
	bool				declared;	//for error check at end
	bool				is_dir;
	int					value;		//del? 
	struct s_undeflab	*head;
}						t_label;

typedef struct s_labtab
{
	t_hashmap	labels;
	t_vec		entries;
}				t_labtab;

#endif
