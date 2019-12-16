/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_dash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:44:02 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 15:46:29 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_not_dash(t_struct *p, char *string)
{
	int i;

	i = 0;
	if (p->flags & WIDTH_OB_FLAG)
		i = ft_not_dash_compl(p, string, i);
	else if (p->flags & PRECI_OB_FLAG)
	{
		if (p->specifier == 'd' || p->specifier == 'i' || p->specifier == 'u'
		|| p->specifier == 'x' || p->specifier == 'X' || p->specifier == 'p')
			i = ft_not_dash_preci(p, string, i);
	}
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
		ft_not_dash_neg(p, string);
	else if (p->specifier == 'p' && p->precision > p->width)
		add_str_buffer(p, string + 2);
	else if (p->specifier == 'c')
		add_to_buffer(p, p->tmp[0]);
	else
	{
		add_str_buffer(p, string);
	}
}

int		ft_not_dash_width_preci(t_struct *p, char *string, int i)
{
	if (p->specifier == 'p')
	{
		add_str_buffer(p, "0x");
		p->string_len = p->string_len - 2;
	}
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
	{
		i++;
		p->string_len--;
	}
	while (ft_max(p->precision, p->string_len) + i < p->width)
	{
		add_to_buffer(p, 32);
		i++;
	}
	i = 0;
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
		add_to_buffer(p, 45);
	while (p->string_len + i < p->precision)
	{
		add_to_buffer(p, 48);
		i++;
	}
	return (i);
}

int		ft_not_dash_width(t_struct *p, char *string, int i)
{
	while (p->string_len + i < p->width)
	{
		add_to_buffer(p, 32);
		i++;
	}
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
	{
		add_to_buffer(p, 45);
		i--;
	}
	return (i);
}

int		ft_not_dash_preci(t_struct *p, char *string, int i)
{
	if (p->specifier == 'p' && p->precision != 0)
	{
		add_str_buffer(p, "0x");
		p->string_len = p->string_len - 2;
	}
	while (p->precision + i < p->width)
	{
		add_to_buffer(p, 32);
		i++;
	}
	i = 0;
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
	{
		add_to_buffer(p, 45);
		p->string_len--;
	}
	while (p->string_len + i < p->precision)
	{
		add_to_buffer(p, 48);
		i++;
	}
	return (i);
}

void	ft_not_dash_neg(t_struct *p, char *string)
{
	if (!(p->flags & WIDTH_OB_FLAG) && !(p->flags & PRECI_OB_FLAG))
	{
		add_to_buffer(p, 45);
		add_str_buffer(p, string + 1);
	}
	else
		add_str_buffer(p, string + 1);
}
