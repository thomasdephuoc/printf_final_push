/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:09:25 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:20:27 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_1 = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	i = 0;
	while (i < n && *(ptr_2 + i) != (unsigned char)c)
	{
		*(ptr_1 + i) = *(ptr_2 + i);
		i++;
	}
	if (*(ptr_2 + i) == (unsigned char)c)
	{
		*(ptr_1 + i) = *(ptr_2 + i);
		return (dst + i + 1);
	}
	return (NULL);
}
