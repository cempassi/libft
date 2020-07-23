/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:35 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_vector	*ft_vctnew(size_t optional_size)
{
	t_vector	*new;
	char		*buffer;

	if (!(new = ft_malloc(sizeof(t_vector))))
		return (NULL);
	if (optional_size > 0)
	{
		if (!(buffer = ft_strnew(optional_size)))
		{
			ft_free(new);
			return (NULL);
		}
		new->size = optional_size;
	}
	else
	{
		if (!(buffer = ft_strnew(VECTOR_BUFFER_SIZE)))
		{
			ft_free(new);
			return (NULL);
		}
		new->size = VECTOR_BUFFER_SIZE;
	}
	new->buffer = buffer;
	return (new);
}
