/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargslst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:43:50 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/25 18:49:58 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_getargslst(int ac, char **av)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 1;
	j = 0;
	lst = NULL;
	while (i < ac && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (i < ac)
		{
			ft_lstadd(&lst, ft_lstnew(av[i], ft_strlen(av[i]) + 1));
			i++;
		}
	}
	return (lst);
}
