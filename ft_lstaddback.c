/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:49:57 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/13 11:28:55 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*holder;

	holder = *alst == NULL ? NULL : *alst;
	if (holder)
	{
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
		return ;
	}
	*alst = new;
	return ;
}
