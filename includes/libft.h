/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:55:01 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/13 00:22:04 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4096
# define BASE_MAX 66
# include <string.h>
# include "ft_printf.h"
# include "list.h"
# include "directory.h"
# include "str.h"
# include "memory.h"
# include "output.h"
# include "conversion.h"
# include "test.h"
# include "other.h"

void				ft_freetab(char ***tab);
char				**ft_getargstab(int ac, char **av);
#endif
