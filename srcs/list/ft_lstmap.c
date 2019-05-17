/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:04:04 by cempassi          #+#    #+#             */
/*   Updated: 2019/05/17 19:13:51 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mapper(t_list *lst, t_list **map, t_lstmod func, t_lstmod del)
{
	t_list	*node;

	if (!lst)
		return (0);
	if (!(node = ft_lstnew(lst->data, lst->data_size)))
	{
		ft_lstdel(map, del);
		return (-1);
	}
	if (func)
		func(node->data);
	ft_lstaddback(map, node);
	return (mapper(lst->next, map, func, del));
}

t_list	*ft_lstmap(t_list *lst, t_lstmod func, t_lstmod del)
{
	t_list	*map;

	map = NULL;
	return (mapper(lst, &map, func, del) ? NULL : map);
}
