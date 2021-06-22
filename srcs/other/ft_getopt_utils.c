/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:53:42 by cempassi          #+#    #+#             */
/*   Updated: 2021/06/22 17:33:33 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_opt(int ac, char **av, int av_index)
{
    int i;

    i = av_index;
    while (i < ac)
    {
        if (av[i][0] == '-' && ft_strcmp(av[i], "--"))
            return (0);
        i++;
    }
    return (1);
}

int check_optarg(int ac, char **av, int av_index)
{
    if (ft_strlen(av[av_index]) > 2)
        return (0);
    if (av_index + 2 > ac)
        return (-1);
    if (av[av_index + 1][0] == '-' || av[av_index + 1][0] == '\0')
        return (-1);
    return (1);
}

int check_optarg_long(int ac, char **av, int av_index)
{
    char *assign;

    if ((assign = ft_strchr(av[av_index], '=')))
    {
        return (assign[1] == '\0' ? -1 : 0);
    }
    else
    {
        if (av_index + 2 > ac)
            return (-1);
        if (av[av_index + 1][0] == '-')
            return (-1);
        if (ft_strncmp(av[av_index], "--", 2))
        {
            if (av[av_index][2] != '\0')
                return (-1);
        }
    }
    return (1);
}

int push_av_back(int ac, char **av, int av_index)
{
    char *holder;
    int   i;

    holder = av[av_index];
    i = av_index;
    while (i < ac)
    {
        av[i] = av[i + 1];
        i++;
    }
    av[i - 1] = holder;
    return (0);
}
