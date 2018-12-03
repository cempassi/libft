/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:06:45 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/27 01:46:15 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void **))
{
	if (!alst || !alst)
		return ;
	if (del)
		del(alst[0]->data);
	else if ((*alst)->data)
		free(alst[0]->data);
	free(*alst);
	*alst = NULL;
}
