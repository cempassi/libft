/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:27:10 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 19:37:36 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(map = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	tmp = map;
	while (*s)
		*tmp++ = f(*s++);
	*tmp = *s;
	return (map);
}
