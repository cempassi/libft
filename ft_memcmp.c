/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:34:46 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 17:43:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	return (*((unsigned char *)s1) != *((unsigned char *)s2) || n == 1 ?
			*((unsigned char *)s1) - *((unsigned char *)s2) :
			ft_memcmp(++s1, ++s2, --n));
}
