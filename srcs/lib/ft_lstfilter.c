/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:12:06 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/25 18:28:49 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract(t_list **h, t_list *c, void *ftr, int (*f)(void *, void *))
{
	if (!c)
		return ;
	if (f(c->data, ftr))
		ft_lstaddback(h, ft_lstnew(c->data, c->data_size));
	return (extract(h, c->next, ftr, f));
}

t_list		*ft_lstfilter(t_list *lst, void *filter, int (*f)(void *, void *))
{
	t_list *new;

	new = NULL;
	extract(&new, lst, filter, f);
	return (new);
}
