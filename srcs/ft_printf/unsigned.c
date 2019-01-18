/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:40:24 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/18 19:29:14 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			u_integer(t_format *format)
{
	char	*tmp;
	int		len;

	tmp = unsigned_convert(format);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}

void	hexadecimal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		i;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, HEXA) : tmp;
	if ((format->precision -= ft_strlen(tmp)) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->flag_hashtag && (format->flag_zero || format->flag_minus))
		format->width -= 2;
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_hashtag && *tmp)
		tmp = prefix(format, tmp);
	if (format->type == 'X' && !(i = 0))
		while ((tmp[i] = ft_toupper(tmp[i])))
			i++;
	if (*holder)
		ft_strdel(&holder);
	format->output = tmp;
	return ;
}

void	octal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, OCTAL) : tmp;
	if (*holder)
		ft_strdel(&holder);
	len = ft_strlen(tmp);
	if (format->flag_hashtag)
		if (*tmp != '0')
			format->precision = ft_strlen(tmp) + 1;
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}

void	binary(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, BINARY) : tmp;
	if (*holder)
		ft_strdel(&holder);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	if (format->flag_hashtag)
	{
		holder = tmp;
		tmp = ft_strjoin("0b", tmp);
		ft_strdel(&holder);
	}
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}