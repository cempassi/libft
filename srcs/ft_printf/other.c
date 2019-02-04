/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:59 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/04 21:37:42 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_printf.h"

static char		*converter(t_format *format)
{
	char		*tmp;
	char		*dst;

	if (format->precision == 0 && format->arg.pointer == NULL)
		dst = NULL;
	else
	{
		tmp = ft_ullitoa((uintptr_t)format->arg.pointer);
		dst = ft_convert_base(tmp, TEN, HEXA);
		ft_strdel(&tmp);
	}
	tmp = ft_strjoin("0x", dst);
	ft_strdel(&dst);
	return (tmp);
}

void			pointer(t_format *format)
{
	char		*tmp;

	tmp = converter(format);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_color)
		tmp = colors(format, tmp);
	format->output = tmp;
	return ;
}

void			string(t_format *format)
{
	char	*tmp;

	if (format->precision == -1)
		tmp = ft_strdup(format->arg.string);
	else
		tmp = ft_strsub(format->arg.string, 0, format->precision);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_color)
		tmp = colors(format, tmp);
	format->output = tmp;
	return ;
}

void			character(t_format *format)
{
	char		*tmp;

	tmp = ft_strnew(1);
	*tmp = format->arg.character;
	format->width = format->width - 1;
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_color)
		tmp = colors(format, tmp);
	format->output = tmp;
	return ;
}
