/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_dash_compl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:42:47 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 15:45:15 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_not_dash_compl(t_struct *p, char *string, int i)
{
	if (p->specifier == 'd' || p->specifier == 'i' || p->specifier == 'u'
	|| p->specifier == 'x' || p->specifier == 'X' || p->specifier == 'p')
	{
		if (p->flags & PRECI_OB_FLAG && !(p->specifier == 'p'
		&& p->precision < p->width))
			i = ft_not_dash_width_preci(p, string, i);
		else
			i = ft_not_dash_width(p, string, i);
	}
	else
	{
		while (p->string_len + i < p->width)
		{
			add_to_buffer(p, 32);
			i++;
		}
	}
	return (i);
}
