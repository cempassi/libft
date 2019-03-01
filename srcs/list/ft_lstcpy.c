/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:30:05 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/01 23:45:59 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 			*ft_lstcpy(t_list *source, void (*cpy)(void *, void *))
{
	t_list		*copy;
	t_list		*node;

	copy = NULL;
	while (source)
	{
		if(!(node = ft_lstnew(source->data, source->data_size)))
			return (NULL);
		cpy(node->data, source->data);
		ft_lstadd(&copy, node);
		source = source->next;
	}
	return (copy);
}
