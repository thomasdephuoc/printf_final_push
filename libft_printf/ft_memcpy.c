/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:58:38 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:20:52 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_1 = (unsigned char*)dst;
	ptr_2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(ptr_1 + i) = *(ptr_2 + i);
		i++;
	}
	return (dst);
}
