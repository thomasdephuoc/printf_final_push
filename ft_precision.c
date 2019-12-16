/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:20:53 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:45:35 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision(t_struct *p, char *string)
{
	if (p->specifier == 's' && p->precision < p->string_len)
	{
		return (ft_str_precision(p, string));
	}
	else if ((p->specifier == 'd' || p->specifier == 'i'
	|| p->specifier == 'u' || p->specifier == 'X' || p->specifier == 'x'))
	{
		p->string_len = ft_strlen(string);
		ft_int_precision(p, string);
		return (string);
	}
	else
	{
		p->string_len = ft_strlen(string);
		return (string);
	}
}

char	*ft_str_precision(t_struct *p, char *string)
{
	if (!(p->string_prec = malloc(sizeof(char) * (p->precision + 1))))
		return (NULL);
	ft_strlcpy(p->string_prec, string, p->precision + 1);
	p->offset = -(p->precision);
	p->string_len = ft_strlen(p->string_prec);
	return (p->string_prec);
}

void	ft_int_precision(t_struct *p, char *string)
{
	(void)string;
	p->offset = p->precision - p->string_len;
	if (p->precision < p->string_len && string[0] != '-')
	{
		p->precision = p->string_len;
	}
}
