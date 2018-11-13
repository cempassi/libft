/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:44:15 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/13 11:25:56 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void		base_convert(char *str, char *base, int baselen, long *result)
{
	int		i;

	i = 0;
	if (*str != '\0')
	{
		while (base[i] != *str)
			i++;
		*result = (*result * baselen) + i;
		base_convert(str + 1, base, baselen, result);
	}
	return ;
}

static long		ft_atoi_base(char *str, char *base, char *buffer, int *index)
{
	int		baselen;
	long	res;

	res = 0;
	baselen = ft_len(base);
	if (str == 0 || *str == '\0')
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str != '-')
	{
		*str == '+' ? base_convert(str + 1, base, baselen, &res) :
			base_convert(str, base, baselen, &res);
	}
	else if (*str == '-')
	{
		base_convert(str + 1, base, baselen, &res);
		buffer[0] = '-';
		*index += 1;
		return (res);
	}
	return (res);
}

static void		converter(long nb, char *base, int index, char *buffer)
{
	if (nb == 0 && index == 0)
	{
		buffer[0] = base[0];
		buffer[1] = '\0';
		return ;
	}
	if (nb > 0)
	{
		converter(nb / ft_strlen(base), base, index + 1, buffer);
		buffer[index] = base[nb % ft_len(base)];
		return ;
	}
	buffer[index] = '\0';
	return ;
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	buffer[34];
	char	*conv_res;
	long	base_ten;
	int		buff_len;
	int		i;

	i = 0;
	base_ten = ft_atoi_base(nbr, base_from, buffer, &i);
	converter(base_ten, base_to, i, buffer);
	buff_len = ft_len(buffer) - 1;
	if (!(conv_res = malloc(sizeof(char) * (ft_strlen(buffer) + i + 1))))
		return (0);
	conv_res[0] = buffer[0] == '-' ? '-' : '0';
	while (buff_len >= 0)
		conv_res[i++] = buffer[buff_len--];
	i = buffer[0] == '-' ? i - 1 : i - 0;
	conv_res[i] = '\0';
	return (conv_res);
}
