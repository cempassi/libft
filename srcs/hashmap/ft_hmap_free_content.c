/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_free_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:20 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:20 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

static void		free_hnode_lst(t_list **ptr, void (*del)(void *))
{
	t_list	*tmp;
	t_hnode	*node;

	while (*ptr != NULL)
	{
		tmp = *ptr;
		*ptr = (*ptr)->next;
		tmp->next = NULL;
		node = (t_hnode *)tmp->data;
		ft_del_hnode(node, del);
		free(tmp);
	}
}

void			ft_hmap_free_content(t_hash *hashmap, void (*del)(void *))
{
	size_t	i;
	t_list	*ptr;

	i = 0;
	if (hashmap->used == 0)
		return ;
	while (i < hashmap->map_size)
	{
		ptr = hashmap->map[i];
		if (ptr)
		{
			free_hnode_lst(&ptr, del);
			hashmap->map[i] = NULL;
		}
		i++;
	}
	hashmap->used = 0;
}
