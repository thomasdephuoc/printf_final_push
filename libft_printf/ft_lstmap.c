/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:37:45 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/12 14:51:03 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lout;
	t_list *p_current;

	lout = 0;
	p_current = 0;
	while (lst != 0)
	{
		p_current = ft_lstnew(f(lst->content));
		if (p_current == 0)
		{
			ft_lstclear(&lout, del);
			return (0);
		}
		ft_lstadd_back(&lout, p_current);
		lst = lst->next;
	}
	return (lout);
}
