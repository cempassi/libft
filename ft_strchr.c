/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 07:35:20 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/19 07:47:41 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	if(!*s)
		return (*s == (char)c ? (char *)s : NULL);
	return (*s == (char)c ? (char *)s : ft_strchr(++s, c));
}

