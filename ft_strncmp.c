/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:32:00 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 17:56:10 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	return (*s1 != *s2 || (!*s1 && !*s2) || n == 1 ?
			*(unsigned char *)s1 - *(unsigned char *)s2 :
			ft_strncmp(++s1, ++s2, --n));
}
