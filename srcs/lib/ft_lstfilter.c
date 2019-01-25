/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:12:06 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/25 23:20:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract(t_list **h, t_list *c, void *ftr, int (*f)(void *, void *))
{
	t_list	*next;

	if (!c->next)
		return ;
	if (f(c->next->data, ftr))
	{
		next = c->next;
		c->next = c->next->next;
		next->next = NULL;
		ft_lstaddback(h, next);
	}
	return (extract(h, c->next, ftr, f));
}

t_list		*ft_lstfilter(t_list **lst, void *filter, int (*f)(void *, void *))
{
	t_list *new;

	new = NULL;
	if (f((*lst)->data, filter))
	{
		new = (*lst);	
		*lst = (*lst)->next;
		new->next = NULL;
	}	
	extract(&new, *lst, filter, f);
	return (new);
}
