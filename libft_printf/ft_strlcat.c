/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:41:03 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:21:36 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t len_src;
	size_t len_dst;
	size_t i;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst > dstsize)
		return (len_src + dstsize);
	while (len_dst + i < dstsize - 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}
