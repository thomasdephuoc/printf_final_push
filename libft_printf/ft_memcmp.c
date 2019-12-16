/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:03:56 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:20:40 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	while (i < n && *(ptr_s1 + i) == *(ptr_s2 + i))
		i++;
	if (i == n)
		return (0);
	else
		return (ptr_s1[i] - ptr_s2[i]);
}
