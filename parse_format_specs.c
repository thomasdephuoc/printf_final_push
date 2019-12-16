/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_specs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:03:12 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:50:19 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_all(t_struct *p)
{
	parse_flags(p);
	parse_width(p);
	parse_precision(p, 0);
}

void	parse_flags(t_struct *p)
{
	while (*p->format == '0' || *p->format == '-')
	{
		if (*p->format == '0')
			p->flags |= ZERO_FLAG;
		else if (*p->format == '-')
			p->flags |= DASH_FLAG;
		p->format++;
	}
}

void	parse_width(t_struct *p)
{
	int width;

	while (!(p->flags & FMT_INVALID)
	&& (*p->format == '*' || ft_isdigit(*p->format)))
	{
		p->flags |= (p->flags & WIDTH_OB_FLAG) ? FMT_INVALID : 0;
		if (!(p->flags & FMT_INVALID) && *p->format == '*')
		{
			p->format++;
			width = va_arg(p->args, int);
			p->flags |= (width < 0) ? DASH_FLAG : 0;
			p->width = ft_abs(width);
			p->flags |= WIDTH_OB_FLAG;
		}
		if (!(p->flags & FMT_INVALID) && ft_isdigit(*p->format))
		{
			p->flags |= (p->flags & WIDTH_OB_FLAG) ? FMT_INVALID : 0;
			while (!(p->flags & FMT_INVALID) && ft_isdigit(*p->format))
				p->width = p->width * 10 + (*(p->format++) - '0');
			p->flags |= WIDTH_OB_FLAG;
		}
	}
}

void	parse_precision(t_struct *p, int recurse_level)
{
	if (!(p->flags & FMT_INVALID) && (*p->format == '.' || recurse_level > 0))
	{
		p->format = (*p->format == '.') ? p->format + 1 : p->format;
		if (*p->format == '*' || ft_isdigit(*p->format))
		{
			p->flags |= (p->flags & PRECI_OB_FLAG) ? FMT_INVALID : 0;
			if (!(p->flags & FMT_INVALID) && *p->format == '*')
			{
				p->format++;
				p->precision = va_arg(p->args, int);
				p->flags |= PRECI_OB_FLAG;
			}
			if (!(p->flags & FMT_INVALID) && ft_isdigit(*p->format))
			{
				p->flags |= (p->flags & PRECI_OB_FLAG) ? FMT_INVALID : 0;
				while (!(p->flags & FMT_INVALID) && ft_isdigit(*p->format))
					p->precision = p->precision * 10 + (*(p->format++) - '0');
				p->flags |= PRECI_OB_FLAG;
			}
			parse_precision(p, recurse_level + 1);
		}
		p->flags |= PRECI_OB_FLAG;
	}
}
