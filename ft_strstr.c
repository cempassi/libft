/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 07:27:59 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/19 08:15:05 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	if(*haystack == '\0')
		return (NULL);
	return(ft_strncmp(haystack, needle, ft_strlen(needle)) == 0 ? 
			(char *)haystack : ft_strstr(++haystack, needle));
}

