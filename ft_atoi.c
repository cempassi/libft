/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:52:12 by cempassi          #+#    #+#             */
/*   Updated: 2018/10/19 10:50:58 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	converter(const char *str, long result, int sign)
{
	int		holder;

	if (!ft_isdigit(*str))
		return (sign == 1 ? result : -result);
	holder = result * 10 + *str - '0';
	if ((sign == 1 && holder >= 214748364 && str[1] > '7') || 
			(sign == -1 && holder >= 214748364 && str[1] > '8'))
		return(-1);
	return (converter(++str, holder, sign));
}

int		ft_atoi(const char *str)
{
	if (!str)
		return (0);
	while (strchr("\f\n\r\t\v ", *str))
		str++;
	if ((*str == '+' && ft_isdigit(str[1])) || ft_isdigit(*str))
		return (*str == '+' ? converter(&str[1], 0, 1) : converter(str, 0, 1));
	if (*str == '-' && ft_isdigit(str[1]))
		return (converter(&str[1], 0, -1));
	return (0);
}
