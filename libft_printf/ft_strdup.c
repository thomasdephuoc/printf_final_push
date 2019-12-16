/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:46:52 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 11:21:30 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*result;

	length = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_strlcpy(result, s1, sizeof(char) * (length + 1));
	return (result);
}
