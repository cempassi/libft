/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:49 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/11 23:55:03 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_dup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(dst, s1));
}

static void		ft_init(void *s, size_t n)
{
	if (!n)
		return ;
	*((char *)s) = 0;
	while (--n > 0)
		((char *)s)[n] = '\0';
}

static int		numlen(long n)
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

static	void	converter(char *buffer, long n, int i)
{
	if (n > 0)
	{
		converter(buffer, n / 10, --i);
		buffer[i] = n % 10 + '0';
	}
}

char			*ft_itoa(int n)
{
	int		flag;
	char	buffer[12];

	if (n == 0)
		return (ft_dup("0"));
	flag = 0;
	ft_init(buffer, 12);
	if (n < 0)
		buffer[flag++] = '-';
	converter(buffer + flag, flag == 0 ? (long)n : -(long)n, numlen(n));
	return (ft_dup(buffer));
}
