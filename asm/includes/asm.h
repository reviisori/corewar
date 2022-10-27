/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:30:34 by altikka           #+#    #+#             */
/*   Updated: 2022/10/27 09:20:30 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "source.h"
//# include "handler.h"

# define ASM_USAGE "\nusage: ./asm [-WIP] <file.s>\n\
 options:\n\
 \t\e[1m-h\e[m\thelp - NOT IMPLEMENTED\n\
 \t\e[1m-q\e[m\tquiet mode - NOT IMPLEMENTED\n\n"

int		valid_file(int argc, char *filename);
void	panic(const char *msg);
int		parse(char *filename);
int		assemble(char *filename);

#endif
