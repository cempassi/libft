/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:37:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/08 13:40:09 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*map;
	char				*tmp;
	unsigned int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(map = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	tmp = map;
	while (s[i])
	{
		*tmp++ = f(i, s[i]);
		i++;
	}
	*tmp = s[i];
	return (map);
}
