/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:18 by cempassi          #+#    #+#             */
/*   Updated: 2020/08/31 17:04:44 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H
# define BUFF_SIZE 4096
# include <string.h>
# include "vector.h"

typedef struct		s_buffer
{
	char			buffer[BUFF_SIZE];
	unsigned int	index;
	unsigned int	room;
}					t_buffer;

typedef struct		s_opt_buffer
{
	t_vector 		*vector;
	unsigned int	index;
	unsigned int 	av_index;
}					t_opt_buffer;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *str);
void				ft_putnstr(char *str, size_t n);
int					ft_putstr_fd(char const *str, int fd);
int					ft_ringbuffer(char *str, int fd);
#endif
