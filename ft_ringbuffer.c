/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ringbuffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:08:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/18 00:11:45 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ringflush(t_buffer *ring)
{
	int				output;

	output = ft_putstr(&ring->buffer[ring->index]);
	ring->index += output;
	if (ring->index >= BUFF_SIZE - 1)
	{
		ring->index = 0;
		ring->room = BUFF_SIZE - 1;
		ring->buffer[0] = '\0';
	}
	return (output);
}

int				ft_ringbuffer(char *str)
{
	static t_buffer ring = {.buffer = NULL, .index = 0, .room = BUFF_SIZE - 1};
	size_t			size;
	size_t			diff;

	if (!ring.buffer)
		if (!(ring.buffer = ft_memalloc(BUFF_SIZE)))
			return (-1);
	if (!str)
		return (ft_ringflush(&ring));
	size = ft_strlen(str);
	if (size > ring.room)
	{
		diff = ring.room;
		ft_strncat(&ring.buffer[ring.index], str, ring.room);
		return (ft_ringflush(&ring) + ft_ringbuffer(&str[diff]));
	}
	ft_strcat(&ring.buffer[ring.index], str);
	return (!(ring.room -= size) ? ft_ringflush(&ring) : 0);
}
