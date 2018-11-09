/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:10:39 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 19:50:39 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char const	*trimmer(char const *s, int *len)
{
	size_t		i;
	char const	*str;

	i = 0;
	while (ft_strchr("\n\t ", s[i]) && s[i])
		i++;
	if (i == ft_strlen(s))
		return (NULL);
	str = s + i;
	while (s[i])
	{
		*len += 1;
		i++;
	}
	while (ft_strchr("\n\t ", s[--i]))
		*len -= 1;
	return (str);
}

char				*ft_strtrim(char const *s)
{
	int			len;
	char		*trim;
	char const	*str;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strdup(s));
	len = 0;
	str = trimmer(s, &len);
	if (str == NULL)
		return (ft_strnew(1));
	if (!(trim = ft_strsub(str, 0, len)))
		return (NULL);
	return (trim);
}
