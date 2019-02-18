/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmpassi <cempassi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:17:54 by cedricmpa         #+#    #+#             */
/*   Updated: 2019/02/18 06:00:58 by cedricmpa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void		signal_catch(int signal)
{
	if (WTERMSIG(signal) == SIGSEGV)
		ft_dprintf(2, "%@s\n", RED, "[SEGV]");
	if (WTERMSIG(signal) == SIGBUS)
		ft_dprintf(2, "%@s\n", RED, "[BUSE]");
	if (WTERMSIG(signal) == SIGABRT)
		ft_dprintf(2, "%@s\n", RED, "[ABRT]");
	if (WTERMSIG(signal) == SIGILL)
		ft_dprintf(2, "%@s\n", RED, "[SILL]");
	if (WTERMSIG(signal) == SIGFPE)
		ft_dprintf(2, "%@s\n", RED, "[FPEX]");
	exit(3);
}

void		init_signal_catcher(void)
{
	if (signal(SIGBUS, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGBUS.");
	if (signal(SIGSEGV, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGABRT, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGILL, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
	if (signal(SIGFPE, signal_catch) == SIG_ERR)
		ft_dprintf(2,"Error occured catching the SIGSEGV.");
}
