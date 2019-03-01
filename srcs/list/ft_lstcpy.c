/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:30:05 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/01 22:32:51 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 			*ft_lstcpy(t_list *source)
{
	t_list		*copy;
	t_list		*node;

	copy = NULL;
	while (source)
	{
		node = ft_lstnew(source->data, source->data_size);	
		ft_lstaddback(&copy, node);
		source = source->next;
	}
	return (copy);
}
