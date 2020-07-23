/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:18 by cempassi          #+#    #+#             */
/*   Updated: 2020/07/23 03:49:29 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checkstat(char *file, mode_t st_mode)
{
	t_stat	info;
	char	*path;

	path = NULL;
	if (*file == '/')
	{
		if (lstat(file, &info) < 0)
			return (-1);
	}
	else
	{
		ft_asprintf(&path, "./%s", file);
		if (path == NULL || lstat(file, &info) < 0)
			return (-1);
		ft_strdel(&path);
	}
	return (info.st_mode & st_mode);
}
