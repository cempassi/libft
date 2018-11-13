/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:56:37 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/13 11:01:55 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **alst, t_list *blst)
{
	t_list *holder;

	holder = *alst;
	if (*alst == NULL)
	{
		*alst = blst;
		return ;
	}
	while (holder->next != NULL)
		holder = holder->next;
	holder->next = blst;
}
