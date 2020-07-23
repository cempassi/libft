/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:20 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:20 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

t_hash	ft_hmap_init(size_t size)
{
	t_hash data;

	data.print_pad = 0;
	data.used = 0;
	data.map_size = size;
	data.map = ft_memalloc(data.map_size * sizeof(t_list *));
	return (data);
}
