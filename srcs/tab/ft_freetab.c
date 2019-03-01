/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:19:35 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/01 22:50:02 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		ft_freetab(char ***tab)
{
	char	**tmp;
	int		i;

	if (!*tab)
		return ;
	tmp = *tab;
	i = 0;
	if (*tab)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(*tab);
	}
	*tab = NULL;
}
