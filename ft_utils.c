/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:02:53 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 14:41:34 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

unsigned long int	ft_max(unsigned long int a, unsigned long int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
