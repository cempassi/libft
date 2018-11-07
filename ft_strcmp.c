/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:30:50 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/16 16:35:57 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	return (*s1 != *s2 || (!*s1 && !*s2) ?
			*(unsigned char *)s1 - *(unsigned char *)s2 :
			ft_strcmp(s1 + 1, s2 + 1));
}
