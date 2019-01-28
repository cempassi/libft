/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 07:17:47 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/28 08:53:40 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ereaser(t_list *current, void *data, int (*test)(t_list *, void *),\
		void (*del)(void **))
{
	t_list		*tmp;

	if (!current)
		return (NULL);
	else if (test(current, data))
	{
		tmp = current->next;
		ft_lstdelone(&current, del);
		tmp = ereaser (tmp, data, test, del);
		return (tmp);
	}
	else
	{
		current->next = ereaser(current->next, data, test, del);
		return (current);
	}
}

void	ft_lstremove_if(t_list **lst, void *data, int (*tst)(t_list *, void *),\
		void (*del)(void **))
{
	t_list		*tmp;

	if (!lst || !*lst || !tst)
		return ;
	if (tst(*lst, data))
	{
		tmp = (*lst)->next;
		ft_lstdelone(lst, del);
		*lst = tmp;
		return (ft_lstremove_if(lst, data, tst, del));
	}
	if ((*lst)->next)
		(*lst)->next = ereaser((*lst)->next, data, tst, del);
}
