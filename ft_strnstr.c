/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 08:18:05 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/09 17:55:39 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0' || len == 0 || ft_strlen(needle) > len)
		return (NULL);
	return (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0 ?
			(char *)haystack : ft_strnstr(++haystack, needle, --len));
}
