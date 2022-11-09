/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:12:18 by altikka           #+#    #+#             */
/*   Updated: 2022/11/09 14:58:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

typedef struct s_undeflab
{
	u_int32_t			op;
	int					arg;
	u_int32_t			loc;
	struct s_undeflab	*next;
}						t_undeflab;

typedef struct s_label
{
	u_int32_t			op;
	bool				declared;
	int					value;
	struct s_undeflab	*head;
}						t_label;

typedef struct s_labtab
{
	t_hashmap	labels;
	t_vec		entries;
}				t_labtab;

#endif
