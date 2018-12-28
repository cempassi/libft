/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 23:13:38 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 23:24:43 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int		numlen(long long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	converter(char *buffer, long long n, int i)
{
	if (n > 0)
	{
		converter(buffer, n / 10, --i);
		buffer[i] = n % 10 + '0';
	}
}

char			*ft_llitoa(long long n)
{
	int		flag;
	int		len;
	char	*buffer;

	if (n == 0)
		return (ft_strdup("0"));
	flag = 0;
	len = numlen(n);
	buffer = ft_strnew(len);
	if (n < 0)
		buffer[flag++] = '-';
	if (n == LLONG_MIN)
	{
		n++;	
		converter(buffer + flag, flag == 0 ? (long)n : -(long)n, len);
		buffer[19] += 1;
	}
	else 
		converter(buffer + flag, flag == 0 ? (long)n : -(long)n, len);
	return (ft_strdup(buffer));
}
