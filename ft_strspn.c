/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:32:40 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/22 17:41:38 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (ft_strchr(charset, *s) == NULL)
			return (i);
		s++;
		i++;
	}
	return (i);
}
