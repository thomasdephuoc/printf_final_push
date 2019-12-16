/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:48:56 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:57:52 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_arg_init(const char *format, va_list args)
{
	t_struct p;

	ft_bzero(&p, sizeof(p));
	va_copy(p.args, args);
	p.format = format;
	p.start = p.format;
	p.fd = 1;
	while (*p.format != '\0')
	{
		while (*p.format != '%' && *p.format != '\0')
		{
			add_to_buffer(&p, *p.format);
			p.format++;
		}
		if (*p.format == '\0')
			break ;
		p.format++;
		ft_printf_ops(&p);
		if (*p.format != '\0')
			p.format++;
	}
	va_end(p.args);
	return (p.len);
}

size_t	ft_printf(const char *format, ...)
{
	va_list args;

	if (format)
	{
		va_start(args, format);
		return (ft_arg_init(format, args));
	}
	return (0);
}

void	reset_printf(t_struct *p)
{
	p->flags = 0;
	p->string_len = 0;
	p->width = 0;
	p->precision = 0;
	p->base = 0;
	p->neg = 0;
	p->hex_int = 0;
	p->specifier = '\0';
	p->offset = 0;
	p->string_itoa = NULL;
	p->string_prec = NULL;
}

void	ft_printf_ops(t_struct *p)
{
	parse_flags(p);
	parse_width(p);
	parse_precision(p, 0);
	ft_convert(p);
	reset_printf(p);
}
