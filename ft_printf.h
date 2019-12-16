/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:40:50 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 15:56:24 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define ZERO_FLAG		1
# define DASH_FLAG		2
# define LDTOA_FRAC		4
# define WIDTH_OB_FLAG	16
# define PRECI_OB_FLAG	32
# define LEN_OB_FLAG	64
# define FMT_INVALID	128
# define NUL_STRING		256
# define BUFF_SIZE		4096

typedef struct		s_struct
{
	const char		*format;
	const char		*start;
	va_list			args;
	int				fd;
	size_t			len;
	size_t			buf_len;
	size_t			string_len;
	int				offset;
	char			zero_offset;
	char			buffer[BUFF_SIZE];
	char			tmp[2];
	char			*string_itoa;
	char			*string_prec;
	int				flags;
	unsigned long	width;
	unsigned long	precision;
	int				base;
	int				neg;
	uintmax_t		hex_int;
	char			specifier;
}					t_struct;

/*
** ft_printf.c
*/

size_t				ft_arg_init(const char *format, va_list args);
size_t				ft_printf(const char *format, ...);
void				reset_printf(t_struct *p);
void				ft_printf_ops(t_struct *p);

/*
** ft_convert.c
*/

void				ft_convert(t_struct *p);
char				*ft_convert_type(t_struct *p);
char				*ft_formatting(t_struct *p, char *string);
char				*ft_pre_formatting(t_struct *p, char *string);

/*
** ft_int_convert.c
*/

char				*ft_int_convert(t_struct *p);

/*
** ft_uns_int_convert.c
*/

char				*ft_uns_int_convert(t_struct *p);
int					ft_uns_init(char **base, unsigned int nb,
					unsigned int *number, int *length);
char				*ft_uns_itoa(t_struct *p, unsigned int nb);

/*
** ft_hexa_convert.c
*/

int					hex_nb_length(unsigned int nb);
char				*ft_hex_int_convert(t_struct *p);
int					ft_hex_init(char **base, unsigned int nb,
					unsigned int *number, int *length);
char				*ft_hex_itoa(t_struct *p, unsigned int nb);
char				*ft_capitalize(char *string);

/*
** ft_percent.c
*/

char				*ft_percent_convert(t_struct *p);

/*
** ft_car_convert.c
*/

char				*ft_car_convert(t_struct *p);

/*
** ft_point_convert.c
*/

char				*ft_point_convert(t_struct *p);
long unsigned int	point_nb_length(long unsigned int nb);
int					ft_point_init(char **base, long unsigned int nb,
					long unsigned int *number, long unsigned int *length);
char				*ft_point_itoa(t_struct *p, long unsigned int nb);

/*
** ft_buffer.c
*/

void				add_to_buffer(t_struct *p, char c);
void				empty_buffer(t_struct *p);

/*
** parse_format_specs.c
*/

void				parse_all(t_struct *p);
void				parse_flags(t_struct *p);
void				parse_width(t_struct *p);
void				parse_precision(t_struct *p, int recurse_level);

/*
** ft_utils.c
*/

int					ft_abs(int a);
unsigned long int	ft_max(unsigned long int a, unsigned long int b);

/*
** ft_fromlibft.c => to replace with libft
*/

int					p_nb_length(unsigned int nb);
void				p_ft_init(char **base, int nb,
					unsigned int *number, int *length);
char				*ft_p_itoa(t_struct *p, int nb);

/*
**	ft_buffer.c
*/

void				add_str_buffer(t_struct *p, char *string);
void				add_to_buffer(t_struct *p, char c);
char				*ft_buff_init(void);

/*
** ft_not_dash.c
*/

void				ft_not_dash(t_struct *p, char *string);
int					ft_not_dash_width_preci(t_struct *p, char *string, int i);
int					ft_not_dash_width(t_struct *p, char *string, int i);
int					ft_not_dash_preci(t_struct *p, char *string, int i);
void				ft_not_dash_neg(t_struct *p, char *string);

/*
** ft_not_dash_compl.c
*/

int					ft_not_dash_compl(t_struct *p, char *string, int i);

/*
** ft_zero.c
*/

void				ft_zero(t_struct *p, char *string);
int					ft_zero_sub_exec(t_struct *p, char *string, int i);
void				ft_zero_remaining_string(t_struct *p, char *string);
int					ft_zero_sub_case_1(t_struct *p, char *string, int i);
int					ft_zero_sub_case_2(t_struct *p, char *string, int i);

/*
** ft_dash.c
*/

void				ft_dash(t_struct *p, char *string);
void				ft_dash_nb(t_struct *p, char *string);
void				ft_dash_nb_prec_part_1(t_struct *p, char *string);
void				ft_dash_nb_prec_part_2(t_struct *p, char *string, int i);
void				ft_dash_text(t_struct *p, char *string);

/*
** ft_precision.c
*/

char				*ft_precision(t_struct *p, char *string);
char				*ft_str_precision(t_struct *p, char *string);
void				ft_int_precision(t_struct *p, char *string);

#endif
