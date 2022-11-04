/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:13 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/04 12:54:58 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTAB_H
# define OPTAB_H

typedef struct s_op
{
	char		*name; //maybe
	u_int8_t	op_code;
	int			args[3];
	int			argc;
	bool		acb;
	struct s_op	*next;
}				t_op;

#endif