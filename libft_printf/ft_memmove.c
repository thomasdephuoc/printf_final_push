/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:51:42 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:20:58 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (ptr_src < ptr_dst)
	{
		while (++i <= len)
			ptr_dst[len - i] = ptr_src[len - i];
	}
	else
	{
		while (len-- > 0)
			*(ptr_dst++) = *(ptr_src++);
	}
	return (dst);
}
