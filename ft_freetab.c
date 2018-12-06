/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:19:35 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/04 03:53:43 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_freetab(char ***tab)
{
	char	**tmp;
	int		i;

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
