/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:31:29 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 16:30:08 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nb_length(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static int	ft_init(char **base, int nb, unsigned int *number, int *length)
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
	*length = *length + nb_length(*number);
	*base = "0123456789";
	return (1);
}

char		*ft_itoa(int nb)
{
	unsigned int	number;
	char			*result;
	int				length;
	char			*base;

	ft_init(&base, nb, &number, &length);
	if (!(result = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	result[length] = '\0';
	length--;
	while (number > 0)
	{
		result[length] = base[number % 10];
		length--;
		number = number / 10;
	}
	if (nb < 0)
	{
		result[length] = '-';
	}
	if (nb == 0)
		result[0] = '0';
	return (result);
}
