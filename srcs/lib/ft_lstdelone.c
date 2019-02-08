/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:06:45 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/08 17:24:40 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *))
{
	if (!alst || !alst)
		return ;
	if (del)
		del((*alst)->data);
	if ((*alst)->data)
		ft_memdel(&(*alst)->data);
	free(*alst);
	*alst = NULL;
}
