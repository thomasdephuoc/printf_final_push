/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:35:47 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/16 14:28:41 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(t_struct *p)
{
	p->specifier = *(p->format);
	if (p->specifier == 'i' || p->specifier == 'd' || p->specifier == 'u'
	|| p->specifier == 'x' || p->specifier == 'X' || p->specifier == '%'
	|| p->specifier == 'c'
	|| p->specifier == 's' || p->specifier == 'p')
	{
		ft_formatting(p, ft_pre_formatting(p, ft_convert_type(p)));
	}
	if (p->specifier == 'i' || p->specifier == 'd'
	|| p->specifier == 'u' || p->specifier == 'x'
	|| p->specifier == 'X' || p->specifier == 'p')
	{
		free(p->string_itoa);
	}
}

char	*ft_convert_type(t_struct *p)
{
	if (p->specifier == 'i' || p->specifier == 'd')
		return (ft_int_convert(p));
	else if (p->specifier == 'u')
		return (ft_uns_int_convert(p));
	else if (p->specifier == 'x')
		return (ft_hex_int_convert(p));
	else if (p->specifier == 'X')
		return (ft_capitalize(ft_hex_int_convert(p)));
	else if (p->specifier == '%')
		return (ft_percent_convert(p));
	else if (p->specifier == 'c')
		return (ft_car_convert(p));
	else if (p->specifier == 's')
		return (va_arg(p->args, char*));
	else if (p->specifier == 'p')
		return (ft_point_convert(p));
	else
		return (NULL);
}

char	*ft_formatting(t_struct *p, char *string)
{
	if (p->flags & PRECI_OB_FLAG)
	{
		string = ft_precision(p, string);
		if (p->specifier == 's')
			free(p->string_prec);
	}
	if (p->specifier == 'c' && p->string_len == 0 && string != NULL)
		p->string_len = 1;
	if (p->flags & ZERO_FLAG && p->flags & DASH_FLAG)
	{
		p->flags ^= ZERO_FLAG;
		ft_dash(p, string);
	}
	else if (p->flags & ZERO_FLAG)
		ft_zero(p, string);
	else if (p->flags & DASH_FLAG)
		ft_dash(p, string);
	else
		ft_not_dash(p, string);
	return (NULL);
}

char	*ft_pre_formatting(t_struct *p, char *string)
{
	if ((int)p->precision < 0 || (p->specifier == '%' && (p->flags & PRECI_OB_FLAG)))
	{
		p->precision = 0;
		p->flags ^= PRECI_OB_FLAG;
	}
	if (p->specifier == '\0')
		return (NULL);
	if (string == NULL)
		string = "(null)";
	if ((p->flags & PRECI_OB_FLAG) && p->precision == 0
	&& (string[0] == 48) && (p->specifier != 'p'
	|| (string == NULL && p->specifier == 'p') || (p->specifier == 'p'
	&& (string[0] == '0' && string[1] == 'x' && string[2] == '0'))))
	{
		string = "";
		if (p->specifier == 'p')
			string = "0x";
	}
	p->string_len = ft_strlen(string);
	return (string);
}
