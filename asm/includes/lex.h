/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:33:03 by atenhune          #+#    #+#             */
/*   Updated: 2022/11/15 15:59:39 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

void	init_lex(t_token *t, t_labtab *lt);
void	panic_lex(const char *msg, size_t row, size_t col);
void	lex_tokenization(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_endof(t_src *s, t_token *t);
void	lex_comment(t_src *s, t_token *t);
void	lex_header(t_sh *d, t_src *s, t_token *t);
void	lex_command(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_argument(t_sh *d, t_src *s, t_token *t, t_labtab *lt);
void	lex_label(t_sh *d, t_src *s, t_labtab *lt, char *key);
void	lex_comma(t_sh *d, t_src *s, t_token *t);
void	validate_separators(t_statement *stmt, int row, int col);

bool	is_label_chars(int c);
bool	is_label(t_src *s);
bool	is_register(t_src *s);
void	calc_arg_size(t_sh *d, t_statement *stmt, const char c);

#endif
