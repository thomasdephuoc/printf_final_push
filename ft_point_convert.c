/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:58:13 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:42:36 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_point_convert(t_struct *p)
{
	return (ft_point_itoa(p, va_arg(p->args, long unsigned int)));
}

long unsigned int	point_nb_length(long unsigned int nb)
{
	long unsigned int i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int					ft_point_init(char **base, long unsigned int nb,
long unsigned int *number, long unsigned int *length)
{
	if (nb == 0)
	{
		*number = nb;
		*length = 1;
	}
	else
	{
		*number = nb;
		*length = 0;
	}
	*length = *length + point_nb_length(*number);
	*base = "0123456789abcdef";
	return (1);
}

char				*ft_point_itoa(t_struct *p, long unsigned int nb)
{
	long unsigned int	number;
	long unsigned int	length;
	char				*base;

	ft_point_init(&base, nb, &number, &length);
	if (!(p->string_itoa = malloc(sizeof(char) * (length + 3))))
		return (NULL);
	length = length + 2;
	p->string_itoa[length] = '\0';
	length--;
	while (number > 0)
	{
		p->string_itoa[length] = base[number % 16];
		length--;
		number = number / 16;
	}
	if (nb == 0)
		p->string_itoa[length] = '0';
	p->string_itoa[0] = '0';
	p->string_itoa[1] = 'x';
	return (p->string_itoa);
}
