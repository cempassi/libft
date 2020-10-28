/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:12:26 by cempassi          #+#    #+#             */
/*   Updated: 2020/09/20 13:00:07 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

static int add_opt_long(unsigned int ac, char **av, t_opt *option,
						t_opt_buffer *opt)
{
	char *short_opt;
	char *str;
	int	  i;

	i = 0;
	while (option->optlong[i])
	{
		str = option->optlong[i];
		if (!ft_strncmp(&av[opt->av_index][2], str, ft_strcspn(str, "=")))
		{
			short_opt = ft_strchr(option->optlong[i], '=') + 1;
			if (ft_strchr(opt->vector->buffer, short_opt[0])
				&& short_opt[1] != ':')
				return (0);
			if (short_opt[1] == ':')
			{
				if (check_optarg_long(ac, av, opt->av_index++))
					return (-1);
			}
			return (vct_scat(opt->vector, short_opt, ft_strlen(short_opt)));
		}
	}
	option->error = av[opt->av_index];
	return (-1);
}

static int add_opt(unsigned int ac, char **av, t_opt *option, t_opt_buffer *opt)
{
	int 	i;
	char 	*current;
	char 	*check;
	int 	optarg;

	i = 1;
	while (av[opt->av_index][i] != '\0')
	{
		current = &av[opt->av_index][i++];
		if ((check = ft_strchr(option->optstr, *current)) == NULL)
			return (-*current);
		if (!ft_strchr(opt->vector->buffer, *current) || check[1] == ':')
		{
			if (vct_add(opt->vector, *current) == -1)
				return (-(*current));
			if (check[1] == ':')
			{
				optarg = check_optarg(ac, av, current, opt->av_index);
				if (optarg == -1)
					return (-(*current));
				opt->av_index += optarg;
				return (vct_add(opt->vector, ':') == -1 ? -*current : *current);
			}
		}
	}
	return (*current);
}

static int parser(unsigned int ac, char **av, t_opt *option, t_opt_buffer *opt)
{
	int error;

	error = 0;
	if (check_opt(ac, av, opt->av_index) || opt->av_index == ac
		|| !ft_strcmp(av[opt->av_index], "--"))
	{
		return (0);
	}
	if (!ft_strncmp(av[opt->av_index], "--", 2))
	{
		error = add_opt_long(ac, av, option, opt);
		opt->av_index++;
	}
	else if (av[opt->av_index][0] == '-')
	{
		error = add_opt(ac, av, option, opt);
		opt->av_index++;
	}
	else
	{
		push_av_back(ac, av, opt->av_index);
	}
	return (error < 0 ? error : parser(ac, av, option, opt));
}

int yield_opt(unsigned int ac, char **av, char **optarg, t_opt_buffer *opt)
{
	char option;
	char *arg;

	option = opt->vector->buffer[opt->index];
	*optarg = NULL;
	arg = NULL;
	if (opt->vector->buffer[opt->index + 1] == ':')
	{
		arg = ft_strchr(av[opt->av_index], option);
		while (arg == NULL && opt->av_index < ac)
		{
			opt->av_index++;
			arg = ft_strchr(av[opt->av_index], option);
		}
		*optarg = arg[1] == '\0' ? av[++opt->av_index] : arg + 1;
		++opt->av_index;
		++opt->index;
	}
	++opt->index;
	return (option);
}

int ft_getopt(int ac, char **av, t_opt *option, char **optarg)
{
	static t_opt_buffer opt = { .vector = NULL, .index = 0, .av_index = 1 };
	int					error;

	if (ac == 1 || av == NULL || option == NULL)
		return (0);
	error = 0;
	if (!opt.vector && !check_opt(ac, av, 1))
	{
		opt.vector = vct_new(0);
		if ((error = parser(ac, av, option, &opt)) != 0)
			return (-error);
		option->first_arg = opt.av_index;
		opt.av_index = 1;
	}
	else if (opt.vector && opt.vector->buffer[opt.index])
		return (yield_opt(ac, av, optarg, &opt));
	else if (opt.vector)
	{
		vct_del(&opt.vector);
		return (-1);
	}
	return (0);
}
