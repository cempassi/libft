/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:15:30 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/04 02:14:51 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		parser(int ac, char **av, const char *optstr, char **opt)
{
	static int	lvl = 1;
	int			flag;
	int			i;

	if (!opt || lvl == ac || !ft_strncmp(av[lvl], "--", 3) || av[lvl][0] != '-')
		return (1);
	i = 1;
	flag = 1;
	while (av[lvl][i] != '\0' && flag)
	{
		flag = av[lvl][i] != '-' && ft_strchr(optstr, av[lvl][i]) ? 1 : 0;
		if (!ft_strchr(*opt, av[lvl][i]) && flag)
			if (!(*opt = ft_strinsert(opt, av[lvl][i], ft_strlen(*opt))))
				flag = 0;
		i++;
	}
	lvl++;
	if (flag == 1 && parser(ac, av, optstr, opt))
		return (1);
	ft_strdel(opt);
	return (-1);
}

int				ft_getopt(int ac, char **av, const char *optstr)
{
	static t_buffer	opt = {.buffer = NULL, .index = 0};

	if (ac == 1 || av == NULL || optstr == NULL)
		return (0);
	if (!opt.buffer && av[1][0] == '-')
	{
		opt.buffer = ft_strnew(0);
		if (parser(ac, av, optstr, &opt.buffer) == -1)
			return ('?');
	}
	if (opt.buffer && opt.buffer[opt.index])
		return ((int)opt.buffer[(++opt.index) - 1]);
	else if (opt.buffer)
		ft_strdel(&opt.buffer);
	return (-1);
}
