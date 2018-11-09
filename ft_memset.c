/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 00:02:39 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 17:33:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	if (!len)
		return (b);
	*((unsigned char *)b) = (unsigned char)c;
	while (--len > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
