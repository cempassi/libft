/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:56:37 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/17 14:41:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
