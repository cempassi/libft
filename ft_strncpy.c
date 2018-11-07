/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:32:26 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/19 16:44:37 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	if (!len)
		return (dst);
	while (*src && len)
	{
		*d++ = *src++;
		len--;
	}
	while (len)
	{
		*d++ = '\0';
		len--;
	}
	return (dst);
}
