/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:04:07 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/11 19:29:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_init(void *s, size_t n)
{
	if (!n)
		return ;
	*((char *)s) = 0;
	while (--n > 0)
		((char *)s)[n] = '\0';
}

static char	*ft_new(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	ft_init(str, size + 1);
	return (str);
}

static char	*ft_cpy(char *dst, const char *src)
{
	char *d;

	d = dst;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dst);
}

static char	*ft_cat(char *s1, const char *s2)
{
	char	*str;

	str = s1;
	while (*str)
		str++;
	while (*s2)
		*str++ = *s2++;
	*str = *s2;
	return (s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_new(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_cpy(join, s1);
	ft_cat(join, s2);
	return (join);
}
