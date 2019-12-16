/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:44:41 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 15:01:40 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dash(t_struct *p, char *string)
{
	int i;

	i = 0;
	if (p->specifier == 'c' || p->specifier == 's' || p->specifier == '%')
		ft_dash_text(p, string);
	else
		ft_dash_nb(p, string);
}

void	ft_dash_nb(t_struct *p, char *string)
{
	int i;

	i = 0;
	if (p->flags & PRECI_OB_FLAG)
		ft_dash_nb_prec_part_1(p, string);
	else
	{
		add_str_buffer(p, string);
		if (p->string_len < p->width)
		{
			while (p->string_len + i < p->width)
			{
				add_to_buffer(p, 32);
				i++;
			}
		}
	}
}

void	ft_dash_nb_prec_part_1(t_struct *p, char *string)
{
	int i;

	i = 0;
	if (p->specifier == 'p')
	{
		add_str_buffer(p, "0x");
		p->string_len = p->string_len - 2;
	}
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
	ft_dash_nb_prec_part_2(p, string, i);
}

void	ft_dash_nb_prec_part_2(t_struct *p, char *string, int i)
{
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
	{
		add_str_buffer(p, string + 1);
		i++;
	}
	else if (p->specifier == 'p' && p->precision > p->width)
		add_str_buffer(p, string + 2);
	else
		add_str_buffer(p, string);
	while (p->string_len + i < p->width)
	{
		add_to_buffer(p, 32);
		i++;
	}
}

void	ft_dash_text(t_struct *p, char *string)
{
	int i;

	i = 0;
	if (p->specifier == 'c')
		add_to_buffer(p, p->tmp[0]);
	else
		add_str_buffer(p, string);
	while (p->string_len + i < p->width)
	{
		add_to_buffer(p, 32);
		i++;
	}
}
