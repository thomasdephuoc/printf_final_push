/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:53:18 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/12/13 12:37:18 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_str_buffer(t_struct *p, char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		add_to_buffer(p, string[i]);
		i++;
	}
}

/*
** Adds an element to the buffer
*/

void	add_to_buffer(t_struct *p, char c)
{
	(void)p;
	write(1, &c, 1);
	p->len++;
}

/*
** Empties the buffer by writing its content to stdout
*/

void	empty_buffer(t_struct *p)
{
	write(p->fd, p->buffer, p->buf_len);
	p->buf_len = 0;
}
