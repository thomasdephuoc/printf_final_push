/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:32:48 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/11 13:21:01 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		trim_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
** Returns -1 if there are only charset in the string
*/

int			find_begin(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while ((char)s1[i])
	{
		while ((char)s1[i] != (char)set[j] && (char)set[j])
			j++;
		if ((char)s1[i] == (char)set[j])
			j = 0;
		if ((char)set[j] == '\0')
			break ;
		i++;
	}
	if ((char)s1[i] == '\0')
		return (-1);
	return (i);
}

/*
** Returns position of the first character of the charset if charset is found
** if looking for "yop" in "helloyop", will return 5
*/

size_t		find_end(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = trim_strlen((char *)s1) - 1;
	j = 0;
	while ((char)s1[i])
	{
		while ((char)s1[i] != (char)set[j] && (char)set[j])
			j++;
		if ((char)s1[i] == (char)set[j])
			j = 0;
		if ((char)set[j] == '\0')
			break ;
		i--;
	}
	return (i);
}

static char	*ft_strnull(void)
{
	char *s;

	s = malloc(1);
	s[0] = 0;
	return (s);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;
	char	*ptr;

	i = 0;
	if (s1 == 0 || set == 0)
		return (ft_strnull());
	begin = find_begin(s1, set);
	if (begin == -1)
	{
		return (ft_strnull());
	}
	end = find_end(s1, set);
	if (!(ptr = (char*)malloc(sizeof(char) * (end - begin + 2))))
		return (NULL);
	while (begin < end + 1)
	{
		ptr[i] = (char)s1[begin];
		++i;
		++begin;
	}
	ptr[i] = '\0';
	return (ptr);
}
