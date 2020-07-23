/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:36 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:12:36 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	generate_summary(t_list **summary, t_result result)
{
	t_list		*node;

	node = ft_lstnew(&result, sizeof(t_result));
	ft_lstaddback(summary, node);
}

void	set_test(t_list **lst, t_result results)
{
	t_list		*node;

	node = ft_lstnew(&results, sizeof(t_result));
	ft_lstaddback(lst, node);
}
