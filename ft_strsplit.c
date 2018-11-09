/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:07:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 19:59:10 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_ncpy(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	if (!len)
		return (dst);
	while (*src && len)
	{
		*d++ = *src++;
		len--;
	}
	while (len)
	{
		*d++ = '\0';
		len--;
	}
	return (dst);
}

static void	parser(char const *s, char c, int *wordnum)
{
	while (*s == c)
		s++;
	if (*s == '\0')
		return ;
	if (*s)
		*wordnum += 1;
	while (*s != c && *s)
		s++;
	return (parser(s, c, wordnum));
}

static int	writer(char const *s, char c, char ***tab, int word)
{
	int		i;

	i = 0;
	while (*s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (s[i] != c && s[i])
		i++;
	if (!(tab[0][word] = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	ft_ncpy(tab[0][word], s, i);
	tab[0][word][i] = '\0';
	return (writer(s + i, c, tab, word + 1));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wordnum;

	if (!s)
		return (NULL);
	wordnum = 0;
	parser(s, c, &wordnum);
	if (!(tab = (char **)malloc(sizeof(char *) * wordnum + 1)))
		return (NULL);
	writer(s, c, &tab, 0);
	tab[wordnum] = NULL;
	return (tab);
}
