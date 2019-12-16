/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:52 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/12 15:17:29 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strnull(void)
{
	char *s;

	s = malloc(sizeof(char *));
	s[0] = 0;
	return (s);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	i;
	char	*s2;

	if (!s || s[0] == '\0')
		return (ft_strnull());
	if (f == NULL)
		return (ft_strnull());
	i = 0;
	length = ft_strlen(s);
	if (!(s2 = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
