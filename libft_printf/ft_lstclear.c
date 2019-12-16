/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:08:36 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/12 14:24:23 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_bis;

	node = *lst;
	if (lst == 0 || *lst == 0)
		return ;
	while (node != NULL)
	{
		node_bis = node;
		node = node->next;
		del(node_bis->content);
		free(node_bis);
	}
	*lst = NULL;
}
