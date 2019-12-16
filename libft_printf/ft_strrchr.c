/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:47:25 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:22:06 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			break ;
	}
	if (s[i] != (char)c)
		return (NULL);
	return ((char *)s + i);
}
