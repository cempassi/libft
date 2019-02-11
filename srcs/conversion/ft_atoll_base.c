/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:47:23 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/17 14:41:17 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	converter(char *str, char *base, int len, long long *res)
{
	int		i;

	i = 0;
	if (*str != '\0')
	{
		while (base[i] != *str)
			i++;
		*res = (*res * len) + i;
		converter(str + 1, base, len, res);
	}
	return ;
}

long long	ft_atoll_base(char *str, char *base)
{
	int			baselen;
	long long	res;

	res = 0;
	baselen = ft_strlen(base);
	if (str == 0 || *str == '\0')
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (ft_strchr("+-", *str) || ft_isdigit(*str))
	{
		ft_isdigit(*str) ? converter(str, base, baselen, &res)
			: converter(str + 1, base, baselen, &res);
	}
	return (res);
}
