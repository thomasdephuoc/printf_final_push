/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:06:08 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 15:23:32 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(t_struct *p, char *string)
{
	int		i;
	char	tmp[2];

	i = 0;
	if (p->specifier != 's' && string[0] == '-'
	&& (!(p->flags & PRECI_OB_FLAG) || !(p->flags & WIDTH_OB_FLAG)))
	{
		tmp[0] = string[0];
		tmp[1] = '\0';
		add_str_buffer(p, tmp);
	}
	if (p->specifier == '%' || p->specifier == 'd' || p->specifier == 'i'
	|| p->specifier == 'u' || p->specifier == 'x' || p->specifier == 'X'
	|| (p->specifier == 'p' && p->precision > p->width) || ((p->specifier == 's'
	|| p->specifier == 'c') && !(p->flags & PRECI_OB_FLAG)))
		i = ft_zero_sub_exec(p, string, i);
	if (p->flags & PRECI_OB_FLAG)
	{
		while (p->string_len + i < p->width)
		{
			add_to_buffer(p, 48);
			i++;
		}
	}
	ft_zero_remaining_string(p, string);
}

int		ft_zero_sub_exec(t_struct *p, char *string, int i)
{
	if (p->flags & PRECI_OB_FLAG && (p->precision < p->width))
		i = ft_zero_sub_case_1(p, string, i);
	else if (p->flags & PRECI_OB_FLAG && (p->precision >= p->width))
		i = ft_zero_sub_case_2(p, string, i);
	else
	{
		if (p->string_len < p->width)
		{
			while (p->string_len + i < p->width)
			{
				add_to_buffer(p, 48);
				i++;
			}
		}
	}
	return (i);
}

int		ft_zero_sub_case_1(t_struct *p, char *string, int i)
{
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
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
		add_to_buffer(p, 45);
	while (p->string_len + i < p->width)
	{
		add_to_buffer(p, 48);
		i++;
	}
	return (i);
}

int		ft_zero_sub_case_2(t_struct *p, char *string, int i)
{
	if (p->specifier == 'p')
	{
		add_str_buffer(p, "0x");
		p->string_len = p->string_len - 2;
	}
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
		p->string_len--;
	if ((p->specifier == 'd' || p->specifier == 'i') && string[0] == '-')
		add_to_buffer(p, 45);
	while (p->string_len + i < p->precision)
	{
		add_to_buffer(p, 48);
		i++;
	}
	return (i);
}

void	ft_zero_remaining_string(t_struct *p, char *string)
{
	if (p->specifier == 's')
		add_str_buffer(p, string);
	else if (string[0] == '-')
		add_str_buffer(p, string + 1);
	else if (p->specifier == 'p' && p->precision > p->width)
		add_str_buffer(p, string + 2);
	else if (p->specifier == 'c')
		add_to_buffer(p, p->tmp[0]);
	else
		add_str_buffer(p, string);
}
