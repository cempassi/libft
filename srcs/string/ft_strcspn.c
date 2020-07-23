/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:32 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:32 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strcspn(const char *s, const char *charset)
{
	int			i;
	const char	*c;

	i = 0;
	while (*s)
	{
		c = charset;
		while (*c)
		{
			if (*s == *c)
				return (i);
			c++;
		}
		s++;
		i++;
	}
	return (i);
}
