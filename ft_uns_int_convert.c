/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:49:37 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:46:49 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uns_int_convert(t_struct *p)
{
	return (ft_uns_itoa(p, va_arg(p->args, unsigned int)));
}

int		ft_uns_init(char **base, unsigned int nb,
unsigned int *number, int *length)
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
	*length = *length + nb_length(*number);
	*base = "0123456789";
	return (1);
}

char	*ft_uns_itoa(t_struct *p, unsigned int nb)
{
	unsigned int	number;
	int				length;
	char			*base;

	ft_uns_init(&base, nb, &number, &length);
	if (!(p->string_itoa = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	p->string_itoa[length] = '\0';
	length--;
	while (number > 0)
	{
		p->string_itoa[length] = base[number % 10];
		length--;
		number = number / 10;
	}
	if (nb == 0)
		p->string_itoa[0] = '0';
	return (p->string_itoa);
}
