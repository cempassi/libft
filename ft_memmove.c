/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:55:32 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/11 17:51:15 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n)
	{
		if ((unsigned long)dst < (unsigned long)src)
			return (ft_memcpy(dst, src, n));
		else
		{
			while (--n > 0)
				((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
			*(unsigned char *)dst = *(unsigned char *)src;
		}
	}
	return (dst);
}
