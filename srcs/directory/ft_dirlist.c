/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 06:53:23 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 07:38:26 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		create_list(DIR *current, char *path, t_list **lst)
{
	t_status	tmp;
	t_list		*node;
	t_dirent	*file;

	if (!(file = (void *)readdir(current)))
		return (0);
	ft_bzero(&tmp, sizeof(t_status));
	ft_asprintf(&tmp.path, "%s/%s", path, file->d_name);
	if (!tmp.path)
		return (-2);
	if (lstat(tmp.path, &tmp.info))
		return (-1);
	if (!(tmp.name = ft_strdup(file->d_name)))
		return (-2);
	if(!(node = ft_lstnew(&tmp, sizeof(t_status))))
		return (-2);
	ft_lstaddback(lst, node);
	return (create_list(current, path, lst));
}

int				ft_dirlist(t_list **dirlist, char *path)
{
	DIR			*current;
	int			ret;

	if ((current = opendir(path)))
		return (-1);
	if ((ret = create_list(current, path, dirlist)))
		return (ret);
	closedir(current);
	return (0);
}