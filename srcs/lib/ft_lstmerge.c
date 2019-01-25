/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:56:37 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/26 00:43:27 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstmerge(t_list **alst, t_list *blst)
{
	t_list *holder;

	holder = *alst;
	if (*alst == NULL)
	{
		*alst = blst;
		return (*alst);
	}
	while (holder->next != NULL)
		holder = holder->next;
	holder->next = blst;
	return (*alst);
}
