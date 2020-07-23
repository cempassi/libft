/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taboneach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:35 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_taboneach(char **current, void *context
							, char *(*mod)(char *, void *))
{
	char		*holder;

	if (current == NULL)
		return (0);
	holder = mod(*current, context);
	ft_strdel(current);
	*current = holder;
	return (ft_taboneach(current, context, mod));
}
