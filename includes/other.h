/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 06:38:15 by cempassi          #+#    #+#             */
/*   Updated: 2019/03/13 00:22:02 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_getopt(int ac, char **av, const char *optstr);

#endif
