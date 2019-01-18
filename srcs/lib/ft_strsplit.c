/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:07:06 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/17 14:41:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	parser(char const *s, char *c, int *wordnum)
{
	while (ft_strchr(c, *s) && *s)
		s++;
	if (*s == '\0')
		return ;
	if (*s)
		*wordnum += 1;
	while (!ft_strchr(c, *s) && *s)
		s++;
	return (parser(s, c, wordnum));
}

static int	writer(char const *s, char *c, char ***tab, int word)
{
	int		i;

	i = 0;
	while (ft_strchr(c, *s) && *s)
		s++;
	if (*s == '\0')
		return (1);
	while (!ft_strchr(c, s[i]) && s[i])
		i++;
	if (!(tab[0][word] = (char *)malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strncpy(tab[0][word], s, i);
	tab[0][word][i] = '\0';
	if (writer(s + i, c, tab, word + 1) == 1)
		return (1);
	else
		ft_strdel(&tab[0][word]);
	return (-1);
}

char		**ft_strsplit(char const *s, char *c)
{
	char	**tab;
	int		wordnum;

	if (!s)
		return (NULL);
	wordnum = 0;
	parser(s, c, &wordnum);
	if (!(tab = (char **)malloc(sizeof(char *) * (wordnum + 1))))
		return (NULL);
	if (writer(s, c, &tab, 0) == -1)
		return (NULL);
	tab[wordnum] = NULL;
	return (tab);
}
