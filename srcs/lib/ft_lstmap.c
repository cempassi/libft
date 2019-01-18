/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:04:04 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/17 14:41:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	mapper(t_list *previous, t_list *current, t_list *lst, t_list *(*f)\
		(t_list *elem))
{
	if (lst)
	{
		current = f(ft_lstnew(lst->data, lst->data_size));
		previous->next = current;
		mapper(current, NULL, lst->next, f);
	}
	else
		previous->next = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;

	if (!(map = f(ft_lstnew(lst->data, lst->data_size))))
		return (NULL);
	mapper(map, NULL, lst->next, f);
	return (map);
}
