/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:37:45 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/23 18:43:45 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*merge(t_list *left, t_list *right, int (*cmp)(void *, void *))
{
	t_list *lst;
	t_list	*head;

	if (cmp(left, right) >= 0)
	{
		head = left;
		left = left->next;
	}
	else
	{
		head = right;
		right = right ->next;
	}
	lst = head;
	while (left && right)
	{
		if (cmp(left, right) >= 0)
		{
			lst->next = left;
			left = left->next;
			lst = lst->next;
		}
		else
		{
			lst->next = right;
			right = right->next;
			lst = lst->next;
		}
	}
	return (head);
}

t_list		*ft_mergesort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*right;
	t_list	*left;
	size_t	middle;
	size_t	i;

	i = 0;
	if ((middle = ft_lstlen (lst) / 2) > 0)
	{
		left = lst;
		while (i < middle)
		{
			lst = lst->next;	
			i++;
		}
		right = lst->next;
		lst->next = NULL;
		left = ft_mergesort(left, cmp);
		right = ft_mergesort(right, cmp);
		lst = merge(left, right, cmp);	
	}
	return (lst);
}
