/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:46:54 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 14:36:30 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (!(ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (i < len_s1)
	{
		ptr[i] = *s1++;
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
