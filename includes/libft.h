/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:18 by cempassi          #+#    #+#             */
/*   Updated: 2020/09/20 12:59:38 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BASE_MAX 66
# define SUCCESS 0
# define FAILURE -1
# define TRUE 1
# define FALSE 0

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
# include "hashmap.h"
# include "vector.h"
# include "get_next_line.h"

typedef struct 	s_opt
{
	const char 		*optstr;
	char 			**optlong;
	char 			*error;
	t_opt_buffer 	buffer;
	size_t 			first_arg;
} 				t_opt;

void				ft_freetab(char ***t);
char				**ft_getargstab(int ac, char **av);
void				ft_showtab(char **t);
int					ft_tabsize(char **tab);
int					ft_taboneach(char **current, void *context
								, char *(*mod)(char *, void *));
int 				check_opt(int ac, char **av, int av_index);
int 				check_optarg(int ac, char **av, char *current, int av_i);
int 				check_optarg_long(int ac, char **av, int av_index);
int 				push_av_back(int ac, char **av, int av_index);
int 				ft_getopt(int ac, char **av, t_opt *option, char **optarg);
#endif
