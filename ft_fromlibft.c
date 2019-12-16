/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fromlibft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:50:55 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:51:43 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_nb_length(unsigned int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void	p_ft_init(char **base, int nb, unsigned int *number, int *length)
{
	if (nb <= 0)
	{
		*number = -nb;
		*length = 1;
	}
	else
	{
		*number = nb;
		*length = 0;
	}
	*length = *length + p_nb_length(*number);
	*base = "0123456789";
}

char	*ft_p_itoa(t_struct *p, int nb)
{
	unsigned int	number;
	int				length;
	char			*base;

	p_ft_init(&base, nb, &number, &length);
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
	if (nb < 0)
	{
		p->string_itoa[length] = '-';
	}
	if (nb == 0)
		p->string_itoa[0] = '0';
	return (p->string_itoa);
}
