/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:49 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 19:56:32 by cempassi         ###   ########.fr       */
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

static	void	converter(char *buffer, long n, int i)
{
	if (n > 0)
	{
		converter(buffer, n / 10, i + 1);
		buffer[i] = n % 10 + '0';
	}
}

static char		*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	holder;

	if (str == NULL)
		return (0);
	i = 0;
	len = 0;
	while (str[++len])
		;
	len--;
	while (i < len)
	{
		holder = str[i];
		str[i] = str[len];
		str[len] = holder;
		i++;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*res;
	char	buffer[12];

	if (n == 0)
	{
		res = ft_dup("0");
		return (res);
	}
	ft_init(buffer, 12);
	i = 0;
	if (n < 0)
		buffer[i++] = '-';
	converter(buffer + i, i == 0 ? (long)n : -(long)n, 0);
	ft_strrev(buffer + i);
	res = ft_dup(buffer);
	return (res);
}
