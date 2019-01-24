/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:38:08 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/24 21:11:13 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_getargs(int ac, char **av)
{
	char	**tab;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tab = NULL;
	while (i < ac && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		tab = (char **)malloc(sizeof(char *) * (ac - i) + 1);
		while (i < ac)
			tab[j++] = av[i++];	
		tab[j] = NULL;
	}
	return (tab);
}
