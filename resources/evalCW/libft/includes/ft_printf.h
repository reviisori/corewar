/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:57:22 by rkyttala          #+#    #+#             */
/*   Updated: 2021/05/02 17:59:29 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_specs
{
	int		space;
	int		pound;
	int		zero;
	int		minus;
	int		plus;
	int		width;
	int		precision;
	char	type;
	int		l;
	int		ll;
	int		long_dbl;
	int		h;
	int		hh;
}	t_specs;

int					ft_printf(const char *format, ...);
int					raw_parse(char *format, t_specs *specs, va_list argp);
int					spec_parse(char *format, t_specs *specs);
void				init_specs(t_specs *specs);
int					scan_flags(char c, t_specs *specs);
int					scan_width(char *format, t_specs *specs);
int					scan_precision(char *format, t_specs *specs, int i);
int					scan_length(char *format, t_specs *specs);
void				scan_specifier(char c, t_specs *specs);
int					is_validspec(char c);
void				validate_flags(t_specs *specs);
int					conv_bridge(t_specs *specs, va_list argp, char type);
int					print_char(t_specs *specs, va_list argp);
int					prep_string(t_specs *specs, va_list argp);
int					print_string(t_specs *specs, char *str, int len);
int					print_pointer(t_specs *specs, va_list argp);
int					to_integer(t_specs *specs, va_list argp);
int					di_output_l(t_specs *specs, char *str, int len, char sign);
int					di_output_r(t_specs *specs, char *str, int len, char sign);
int					di_output(t_specs *specs, char *str, int len, char sign);
int					to_octal(t_specs *specs, va_list argp);
int					o_output_l(t_specs *specs, char *str, int len);
int					o_output_r(t_specs *specs, char *str, int len);
int					to_unsigned(t_specs *specs, va_list argp);
int					u_output(t_specs *specs, char *str, int len);
int					to_hex(t_specs *specs, va_list argp, int upper);
int					x_output_l(t_specs *specs, char *str, int len, char *pref);
int					x_output_r(t_specs *specs, char *str, int len, char *pref);
int					x_output(t_specs *specs, char *str, int len, char *pref);
int					to_float(t_specs *specs, va_list argp);
char				*f_zero(int precision);
int					f_output(t_specs *specs, char *str, char sign, int len);
int					f_output_l(t_specs *specs, char *str, char sign, int len);
int					f_output_r(t_specs *specs, char *str, char sign, int len);
int					oux_zeroprecision(t_specs *specs);
unsigned long long	oux_length(t_specs *specs, va_list argp);
long long			di_length(t_specs *specs, va_list argp);
int					print_percent(t_specs *specs);
int					is_signed(t_specs *specs, char sign);
#endif
