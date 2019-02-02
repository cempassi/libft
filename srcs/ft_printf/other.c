/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:59 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/02 19:59:39 by cedricmpa        ###   ########.fr       */
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
	char		*width;

	tmp = converter(format);
	format->width = format->width - ft_strlen(tmp);
	width = NULL;
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		ft_memset(width, ' ', format->width);
	}
	if (format->flag_minus)
		format->output = ft_strjoin(tmp, width);
	else
		format->output = ft_strjoin(width, tmp);
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}

void			string(t_format *format)
{
	char	*tmp;
	char	*width;

	width = NULL;
	if (format->precision == -1)
		tmp = ft_strdup(format->arg.string);
	else
		tmp = ft_strsub(format->arg.string, 0, format->precision);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		if (format->flag_zero && !format->flag_minus)
			ft_memset(width, '0', format->width);
		else
			ft_memset(width, ' ', format->width);
	}
	format->output = format->flag_minus ? ft_strjoin(tmp, width)
										: ft_strjoin(width, tmp);
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}

void			character(t_format *format)
{
	char		*tmp;
	char		*width;

	width = NULL;
	tmp = ft_strnew(1);
	*tmp = format->arg.character;
	format->width = format->width - 1;
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		if (format->flag_zero && !format->flag_minus)
			ft_memset(width, '0', format->width);
		else
			ft_memset(width, ' ', format->width);
	}
	if (format->flag_minus)
		format->output = ft_strjoin(tmp, width);
	else
		format->output = ft_strjoin(width, tmp);
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}

void			color(t_format *format)
{
	format->output = ft_strdup(format->arg.string); 
}
