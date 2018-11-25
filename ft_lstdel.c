/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:56:27 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/24 21:45:30 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*eraser(t_list *current, void (*del)(void *, size_t))
{
	if (current)
	{
		eraser(current->next, del);
		ft_lstdelone(&current, del);
	}
	return (NULL);
}

void			*ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return (NULL);
	*alst = eraser(*alst, del);
	return (NULL);
}
