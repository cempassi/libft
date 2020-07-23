/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctreset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:35 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vctreset(t_vector *vct)
{
	char *new;

	if (!(new = ft_strnew(VECTOR_BUFFER_SIZE)))
		return (1);
	ft_strdel(&(vct->buffer));
	vct->buffer = new;
	vct->size = VECTOR_BUFFER_SIZE;
	return (0);
}
