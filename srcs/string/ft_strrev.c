/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:34 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:34 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int a;
	int b;

	b = 0;
	if (!str)
		return (NULL);
	while (str[b])
	{
		b++;
	}
	b--;
	a = 0;
	while (a < b)
	{
		str[a] ^= str[b];
		str[b] ^= str[a];
		str[a] ^= str[b];
		a++;
		b--;
	}
	return (str);
}
