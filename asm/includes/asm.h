/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:30:34 by altikka           #+#    #+#             */
/*   Updated: 2022/11/23 13:09:39 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "optab.h"
# include "source.h"
# include "sh.h"
# include "parse.h"
# include "symtypes.h"
# include "label.h"
# include "lex.h"

# define ASM_USAGE "\nusage: ./asm [-WIP] <file.s>\n\
 options:\n\
 \t\e[1m-h\e[m\thelp - NOT IMPLEMENTED\n\
 \t\e[1m-q\e[m\tquiet mode - NOT IMPLEMENTED\n\n"

int		valid_file(int argc, char *filename);
void	panic(const char *msg);
int		parse(t_sh *d, char *filename);
int		assemble(t_sh *d, char *filename);
int		write_file(t_sh *d, const int fd);
char	*create_filename(char *src);

#endif
