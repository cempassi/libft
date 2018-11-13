/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:09:07 by cempassi          #+#    #+#             */
/*   Updated: 2018/11/13 11:29:15 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *alst, void *to_find, int (*f)(t_list *, void *))
{
	if (alst == NULL)
		return (alst);
	return ((*f)(alst, to_find) == 0 ? alst :
			ft_lstfind(alst->next->next, to_find, f));
}
