/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:53:07 by cempassi          #+#    #+#             */
/*   Updated: 2019/05/15 17:00:56 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstiter(t_list *lst, t_lstmod func)
{
	if (lst)
	{
		func(lst->data);
		ft_lstiter(lst->next, func);
	}
}
