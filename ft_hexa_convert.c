/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:36:37 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:39:18 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_int_convert(t_struct *p)
{
	return (ft_hex_itoa(p, va_arg(p->args, unsigned int)));
}

int		hex_nb_length(unsigned int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int		ft_hex_init(char **base, unsigned int nb,
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
	*length = *length + hex_nb_length(*number);
	*base = "0123456789abcdef";
	return (1);
}

char	*ft_hex_itoa(t_struct *p, unsigned int nb)
{
	unsigned int	number;
	int				length;
	char			*base;

	ft_hex_init(&base, nb, &number, &length);
	if (!(p->string_itoa = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	p->string_itoa[length] = '\0';
	length--;
	while (number > 0)
	{
		p->string_itoa[length] = base[number % 16];
		length--;
		number = number / 16;
	}
	if (nb == 0)
		p->string_itoa[0] = '0';
	return (p->string_itoa);
}

char	*ft_capitalize(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 97 && string[i] <= 122)
			string[i] = string[i] - 32;
		i++;
	}
	return (string);
}
